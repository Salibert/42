import { configServeur, configDB } from './serveur/config/config'
import mysql from 'mysql2'


const con =  process.platform === 'linux' ?
  mysql.createConnection({
    host: configDB.host,
    user: configDB.user,
    password: 'root'
  })
:
  mysql.createConnection({
    socketPath: configDB.socket,
    user: configDB.user,
    password: ''
  })

var mypromise = new Promise((resolve, reject) => {
  try {
    con.connect((error, result) => {
      if (error) throw error
      else {
        console.log("Connected to DataBase")
        con.query(`CREATE DATABASE IF NOT EXISTS ${configDB.database}`, (error, result) => {
            if (error)
            {
              throw error;
            } else {
              console.log(`Database ${configDB.database} created`);
              resolve()
            }
        })
      }
    })
  } catch (e) { console.error(e) }
})

mypromise.then(() => {
  console.log("MATCHA");
  try {

    con.query(`USE ${configDB.database}`, (error) => {
      if (error) {throw error}
    })

    con.query(`CREATE TABLE IF NOT EXISTS users (
        id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        status BOOLEAN DEFAULT false,
        token VARCHAR(255),
        login VARCHAR(255) NOT NULL,
        firstname VARCHAR(255),
        lastname VARCHAR(255),
        password VARCHAR(255),
        birthdate DATETIME,
        reg_date DATETIME,
        email VARCHAR(255),
        localisation VARCHAR(255),
        sizezone SMALLINT DEFAULT '150',
        gender TINYINT DEFAULT '1',
        targetsexe INT(1) DEFAULT '3',
        popularity INT(11) DEFAULT '0',
        socketId VARCHAR(255),
        image1 VARCHAR(255),
        image2 VARCHAR(255),
        image3 VARCHAR(255),
        image4 VARCHAR(255),
        image5 VARCHAR(255),
        latitude VARCHAR(255),
        longitude VARCHAR(255),
        bio TEXT,
        tags TEXT,
        mylike JSON,
        liked JSON,
        matchs JSON,
        notif JSON,
        myblock JSON,
        blocked JSON,
        usr_report JSON,
        report TINYINT DEFAULT 5
        )` , (error, result) => {
          if (error){ throw error }
          else console.log("Table `users` created");
      });

      con.query(`CREATE TABLE IF NOT EXISTS all_tags(
        id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        name_tags TEXT NOT NULL,
        list_users TEXT NOT NULL
        )`, (error, result) => {
        if (error) { throw error}
        else console.log("Table all_tags created");
      });

      con.query(`CREATE TABLE IF NOT EXISTS chats(
        id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        user1 INT(11) UNSIGNED,
        user2 INT(11) UNSIGNED,
        messages JSON
        )`, (error, result) => {
        if (error) { throw error}
        else console.log("Table chats created");
      });

    } catch (e) { console.error(e) }

    con.end()
})
