import { configDB } from './config'
import mysql from 'mysql2'

export const con =  process.platform === 'linux' ?
  mysql.createConnection({
    host: configDB.host,
    user: configDB.user,
    password: 'root',
    database: configDB.database
  })
:
  mysql.createConnection({
    socketPath: configDB.socket,
    user: configDB.user,
    password: '',
    database: configDB.database
  })

export var sendmail = require('sendmail')({
    logger: {
    },
    silent: true,
    devPort: 1025
  })
