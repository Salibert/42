import User from '../models/userDB'
import fs from 'fs-extra'
import formidable from 'formidable'
import path from 'path'
import util from 'util'
import SHA1 from 'sha1'
import multer from 'multer'
import _ from 'lodash'

const storage = multer.diskStorage({
  destination: function (req, file, cb) {
    User.selectLogin(req.params.login)
    .then(data => {
      req.params.id = data[0].id
      let check = file.mimetype.split('/'),
          mime = ['gif','jpeg','png','jpg']
      if (check[0] != "image" || mime.indexOf(`${check[1]}`) === -1){
        console.error('Mimetype invalid');
        cb(new Error('invalid extention'))
      } else {
        fs.mkdir(`${__dirname}/../public/${data[0].id}`, (err) => {
          if (err && err.code != 'EEXIST'){
            console.error(err);
          }
          if (file.originalname.match(/\.jpg$|.gif$|.png$|jpeg$/i)) {
            let oldPicture = data[0][`image${req.params.index}`]
            if (oldPicture) {
              let nameOldPicture = oldPicture.split('/')
              nameOldPicture = nameOldPicture[nameOldPicture.length - 1]
              fs.unlink(`${__dirname}/../public/${data[0].id}/${nameOldPicture}`, (err) => {
                if (err && err.code != 'ENOENT') {
                  console.error(err);
                }
              })
            }
            cb(null, `${__dirname}/../public/${data[0].id}`)
          } else {
            console.error('invalid extention');
            cb(new Error('invalid extention'))
          }
        })
      }
    })
    .catch(err => {
      console.error(err);
      cb(new Error('File not valid'))
    })
  },
  filename: function (req, file, cb) {
    let extend = file.originalname.split('.')
    if (extend.length === 2 && extend[0] != ""){
      let newNamePicture = `${Date.now()}.${extend[1]}`,
          image = {
            [`image${req.params.index}`]: `http://localhost:5000/static/${req.params.id}/${newNamePicture}`
          }
      User.modifProfile(image, req.params.login)
      .then(cb(null, newNamePicture))
      .catch(err => {
        console.error(err);
        cb(new Error('File not valid (extend)'))
      })
    } else {
      console.log('File the not valid (extend)');
      cb(new Error('File not valid (extend)'))
    }
  }
})

const upload = multer({ storage }).single('file')

const ret = {
  data: null,
  statusMessage: '',
}

module.exports = (router) => {

    router.post('/usr/createAccount', (req, res) => {
      User.createUser(req.body)
      .then(success => {
        ret.statusMessage = success
        res.status(200).json(ret)
      })
      .catch(err => {
          res.statusMessage = err || "internal server error"
          res.status(400).end();
      })
    }),

    router.get('/usr/actionUser/:action/:email', (req, res) => {
      let data = req.params
      User.helpUser(data.email, data.action)
      .then(data => {
        ret.statusMessage = "email resend, you cant check your email"
        res.status(200).json(ret)
      })
      .catch(error => {
        res.statusMessage = error || 'internal server error'
        res.status(400).end()
      })
    })

    router.post('/usr/pullMatchs/:id', (req, res) => {
      let listMatch = req.body,
          id = req.params.id
      User.pullMatchs(listMatch, "PUBLIC")
      .then(data => {
        ret.data = data
        ret.statusMessage = "Good Luck Bro"
        res.status(200).json(ret)
      })
      .catch(err => {
        res.statusMessage = err || "internal server error"
        res.status(400).end();
      })
    }),

    router.post('/usr/auth/:login/', (req, res) => {
      const auth = {
        login: req.params.login,
        password: req.body.password
      }
      User.whoami(auth.login, auth.password)
      .then(success => {
          ret.statusMessage = "Welcome "+ success.login
          ret.data = success
          res.status(200).json(ret)
      })
      .catch(err => {
        res.statusMessage = err || "internal server error"
        res.status(400).end();
      })
    }),

    router.post('/usr/:login/modif', (req , res) => {
      const login = req.params.login
      User.modifProfile(req.body, login)
      .then(success => {
        ret.statusMessage = 'your profile was update'
        ret.data = success[0]
        res.status(200).json(ret)
      })
      .catch(err => {
        res.statusMessage = err || "internal server error"
        res.status(400).end();
      })
    }),

    router.post('/usr/:login/notification/modif', (req , res) => {
      const login = req.params.login
      User.modifNotif(req.body, login)
      .then(success => {
        ret.statusMessage = success[1]
        ret.data = success[0]
        res.status(200).json(ret)
      })
      .catch(err => {
        res.statusMessage = err || "internal server error"
        res.status(400).end();
      })
    }),

    router.get('/usr/actifAccount/:id/:token', (req, res) => {
        const data = req.params
        User.actifAccount(data.id, data.token)
        .then(success => {
          ret.statusMessage = "Welcome "+ success.login
          ret.data = success
          res.status(200).json(ret)
        })
        .catch(err => {
          res.statusMessage = err || 'internal server error'
          res.status(400).end();
        })
    }),

    router.post('/usr/ForgetMyPassword/:id/:token', (req, res) => {
      const data = req.params
      const password = req.body
      User.forgetMyPassword(data.id, data.token, password)
      .then(success => {
        ret.statusMessage = "your password has been changed"
        ret.data = success
        res.status(200).json(ret)
      })
      .catch(err => {
        console.log(err);
        ret.statusMessage = err || 'internal server error'
        res.status(400).end()
      })
    })

    router.get('/usr/checkemail/:email', (req, res) => {
      const email = req.params.email
      User.existMail(email)
      .then(success => {
        res.status(200)
      })
      .catch(err => {
        res.statusMessage = err || "internal server error"
        res.status(400).end();
      })
    }),

    router.get('/usr/getMessages/:senderId/:reciverId', (req, res) => {
      let ids = req.params
      User.pullMessages(ids).then(data => {
        res.status(200).json(data)
      }).catch(err => {
        res.statusMessage = err || "internal server error"
        res.status(400).end();
      })
    }),

    router.post('/usr/uploadPicture/:login/:index', (req, res) => {
      upload(req, res, function (err) {
        if (err){
          res.status(400).json({statusMessage: err})
        } else {
          User.selectLogin(req.params.login)
          .then(data => {
            data[0].tags = _.pull(_.split(data[0].tags , "/"), "")
            res.status(200).json({
              data: data[0],
              statusMessage: "picture upload"
            })
          })
          .catch(err => {
            res.statusMessage = err || "internal server error"
            res.status(400).end();
          })
        }
      })
    })
}
