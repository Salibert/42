import express from 'express'
import bodyParser from 'body-parser'
import { configServeur } from './config/config'
import 'babel-polyfill'
import path from 'path'
import cors from 'cors'
import event from './event/index'
const app = express()
const server = require('http').createServer(app);

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', '*')
  res.header('Access-Control-Allow-Headers', '*, X-Expiry, X-Client, X-Access-Token, X-Uuid, Content-Type, Authorization')
  next()
})
app.use(cors())
app.use(bodyParser.json({limit: '5mb'}))
app.use(bodyParser.urlencoded({limit: '5mb',extended: true}))
app.use('/static', express.static(path.join(__dirname, 'public')))

const router = express.Router()

require('./routes')(router)
app.use('/', router)

global.io = require('socket.io')(server)

io.on('connection', (socket) => {
  console.log('connection');
  event(socket)
 })

 server.listen(5000, function(){
   console.log('listening on 5000');
 })
