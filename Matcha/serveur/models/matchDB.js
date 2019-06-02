import async from 'async'
import User from './userDB'
import { con } from '../config/connect'
import moment from 'moment'
import _ from 'lodash'

con.connect((err) => {
  if (err)
  console.error('error connect :', err)
})

const match = {

}

module.exports = match
