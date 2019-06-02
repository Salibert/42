import match from '../models/matchDB'
import User from '../models/userDB'

const ret = {
  data: null,
  msg: ''
}

module.exports = (router) => {

  router.post('/match/filtre/:id', (req, res) => {
    let filtre = req.body,
        id = req.params.id
    User.filtre(filtre, Number(id))
    .then(data => {
      ret.data = data
      ret.msg = "Good Luck Bro"
      res.status(200).json(ret)
    })
    .catch(err => {
      console.log(err);
      res.statusMessage = err || "internal server error"
      res.status(400).end();
    })
  }),

  router.get('/match/:login/:target', (req, res) => {
    var target = req.params.target
    User.existLogin(target)
    .then(err => {
      ret.msg = "bad request"
      res.status(400).json(ret)
    })
    .catch(err => {
      res.statusMessage = err[0] || "internal server error"
      res.status(400).end();
    })
  }),

  router.get('/match/:idUser/:idTarget/:action', async (req,res) => {
    var data = req.params
    try {
      let check = await User.pullMatchs([data.idUser, data.idTarget], "PRIVATE")
      if (check.length != 2)
      {
        ret.msg = "ERROR"
        res.status(400).json(ret)
      } else {
        let user = check[0],
            target = check[1]
        if (user.id != data.idUser) {
          user = check[1]
          target = check[0]
        };
        switch(data.action){
          case 'Like':
            ret.data = await match.like(user, target)
            break
          case 'Block':
            ret.data = await match.block(user, target)
            break
          case 'Report':
            ret.data = await match.report(user, target)
            break
        }
      }
    } catch(e){
      ret.msg = e.msg
      ret.data = e.data
    } finally {
      if (!ret.data && ret.msg){
        if (!ret.msg)
          ret.msg = `bad request in ${data.action} function`
        res.status(400).json(ret)
      } else {
        res.status(200).json(ret)
      }
    }
  })
}
