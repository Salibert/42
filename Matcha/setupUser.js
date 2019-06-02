import { con } from './serveur/config/connect'
import mysql from 'mysql2'
import SHA from 'sha1'

con.connect((err) => {
  if (err)
    console.error('error connect : ', err)
})

const Sebastien = {
  login: "Salibert3",
  firstname: "Sebastien",
  lastname: "Alibert",
  email: "gustave@gmail.com",
  password: SHA("Salibert(1"),
}
const password_Marco = SHA("Marco(1"),
      password_bob = SHA("BobZoo(1"),
      password_patrick = SHA("PartickZoo(1"),
      password_Ecureil = SHA("ECUREUIL(1"),
      password_Coucou = SHA("Ninja(1"),
      password_fake = SHA('Fake(123')

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, birthdate, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, latitude, longitude, status)
VALUES( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,  ?, ?, ?, ?, ?, ?,'1')`,
[Sebastien.login, Sebastien.firstname, Sebastien.lastname, Sebastien.email, Sebastien.password, "", 'http://restotel.net/wp-content/uploads/statut_bruxelles.jpg', '1995-04-27', '/','[]', '[]', '[]', '[]', '[]', '[]', '[]', '52.1679', '1.9563'], (err) => {
  if (err) {
    console.error('error setupUser Salibert :', err);
  } else {
    console.log("Create Salibert");
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, birthdate, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, latitude, longitude, status)
VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,  ?, ?, ?, ?, ?, ?,'1')`,
["Marco3", "Marco", "Polo", "Marco@free.fr",password_Marco, "", 'http://www.italymagazine.com/sites/default/files/feature-story/leader/marco-polo.jpg', '1955-07-09' ,'/', '[]', '[]', '[]', '[]', '[]', '[]', '[]', '52.1679', '1.9563'], (err) => {
  if (err) {
    console.error('error setupUser Marco :', err);
  } else {
    console.log("Create Marco");
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, birthdate, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, latitude, longitude, status)
VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,  ?, ?, ?, ?, ?, ?, '1')`,
["Bob3", "Bob", "Eponge", "Bob@free.fr",password_bob, "", 'https://i.skyrock.net/6078/2996078/pics/55812936.jpg', '1997-05-01', '/','[]', '[]', '[]', '[]', '[]', '[]', '[]', '45.54656', '6.878'], (err) => {
  if (err) {
    console.error('error setupUser BOB :', err);
  } else {
    console.log("Create BOB");
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, birthdate, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, status)
VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,  ?, ?, ?, ?, '1')`,
["Patrick3", "Patrick", "Etoile", "Patrick@free.fr",password_patrick, "", 'http://vignette2.wikia.nocookie.net/spongebob/images/e/e2/Muscular_Patrick.png/revision/latest?cb=20161210224400', '1997-05-01',  '/','[]', '[]', '[]', '[]', '[]', '[]', '[]'], (err) => {
  if (err) {
    console.error('error setupUser PATRICK :', err);
  } else {
    console.log("Create PATRICK");
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, birthdate,image1, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report,status)
VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,  ?, ?, ?, ?,'1')`,
["Ecureil3", "Ecureil", "Jesaispas", "Ecureil@free.fr",password_Ecureil, "", '1900-05-09','http://img11.hostingpics.net/pics/146292s02e08_10.jpg',  '/','[]', '[]', '[]', '[]', '[]', '[]', '[]', '[]'], (err) => {
  if (err) {
    console.error('error setupUser Ecureil :', err);
  } else {
    console.log("Create Ecureil");
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, status)
VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,  ?, ?, ?, ?, ?, ?,'1')`,
["Coucou3", "Coucou", "toi", "Coucou@free.fr",password_Coucou, "", 'http://www.onlineseduction.fr/wp-content/uploads/2016/02/comment-oublier-une-fille.jpg', '1924-09-05', '2',  '/', '[]', '[]', '[]', '[]', '[]', '[]', '[]', 'appelle se numero 0651509905 t inquite c est gratuit'], (err) => {
  if (err) {
    console.error('error setupUser Coucou :', err);
  } else {
    console.log("Create Coucou");
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,'1')`,
          [
            /* 1.login */
            'Melissa92',
            /* 2.firstname */
            "Leigh",
            /* 3.lastname */
            "Melissa",
            /* 4.email */
            "Melissa92@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1 */
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/13124494_1331955836832741_5863617321733596147_n.jpg?oh=faa1a2aaa7ba937da6f6b809ee2b27eb&oe=5A572EE4',
            /* 8.image2 */
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/10620651_945053732189622_6195221664920087782_n.jpg?oh=ed52f28a23aa8db58a3ed093d7398d96&oe=5A128655',
            /* 9.birthdate */
          '1990-05-31',
           /* 10.gender */
          '2',
          /* 11.filtre */
          '/Fake/Brasil/Ete/',
          /* 12.mylike */
          '[]',
          /* 13.liked */
          '[]',
          /* 14.matchs */
          '[]',
          /* 15.notif */
          '[]',
          /* 16.myblock */
          '[]',
          /* 17.blocked */
          '[]',
          /* 18.usr_report */
          '[]',
          /* 19.bio */
          'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam accumsan tempor pellentesque. Duis convallis arcu odio, ut pharetra justo euismod eget. Pellentesque lorem felis, hendrerit at consequat ut, volutpat sit amet ante. Curabitur est libero, suscipit ac sodales in, ornare quis ipsum. Sed lacus felis, molestie ac commodo id, hendrerit vel leo. Mauris urna purus, facilisis eu posuere sed, aliquam in nisi. Quisque in dignissim velit. Nulla vel neque vulputate, cursus erat non, rutrum turpis. Cras tellus mauris, efficitur id est vel, molestie placerat nunc. Donec mi augue, egestas vitae ullamcorper quis, feugiat nec tortor. Fusce ornare dolor molestie, aliquet quam sed, lobortis nisl.',
          /* 20.longitude*/
          '48.15',
          /* 21.latitude */
          '2.929',
          /* 22.status */
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser Melissa92 -> ', err);
  } else {
    console.log('Create Melissa92');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, image3, image4,birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, '1')`,
          [
            /* 1.login */
            'Xiao03',
            /* 2.firstname*/
            "Xiao",
            /* 3.lastname */
            "Wei",
            /* 4.email */
            "XiaoWei02@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/182037_142573589139398_6679479_n.jpg?oh=2f99b6a0bd64a612c48fccc5c9986eef&oe=5A480F11',
            /* 8.image2 */
          'https://www.facebook.com/photo.php?fbid=137548429641914&set=a.122344214495669.17170.100001602744735&type=3&theater',
          /* 9.image3 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/165355_136303249766432_4358068_n.jpg?oh=414f79b507f18b3cc23e3401a4ac98fb&oe=5A4A3D38',
          /* 10.image4 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/166358_136302943099796_6336835_n.jpg?oh=107e49d411d2bd877947e6c5f2bfd055&oe=5A4C9AB1',
          /* 11.birthdate */
          '1980-09-03',
          /* 12.gender */
          '1',
          /* 13.tags */
          '/Fake/Gay/Hiver/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam accumsan tempor pellentesque. Duis convallis arcu odio, ut pharetra justo euismod eget. Pellentesque lorem felis, hendrerit at consequat ut, volutpat sit amet ante. Curabitur est libero, suscipit ac sodales in, ornare quis ipsum. Sed lacus felis, molestie ac commodo id, hendrerit vel leo. Mauris urna purus, facilisis eu posuere sed, aliquam in nisi. Quisque in dignissim velit. Nulla vel neque vulputate, cursus erat non, rutrum turpis. Cras tellus mauris, efficitur id est vel, molestie placerat nunc. Donec mi augue, egestas vitae ullamcorper quis, feugiat nec tortor. Fusce ornare dolor molestie, aliquet quam sed, lobortis nisl.',
          /* 22.targetsexe */
          '1',
          /* 23.longitude */
          '49.56',
          /* 24.latitude */
          '3.678',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser Xiao2 -> ', err);
  } else {
    console.log('Create Xiao2');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, image3, image4,birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, '1')`,
          [
            /* 1.login */
            'MaasTaurus69',
            /* 2.firstname*/
            "David",
            /* 3.lastname */
            "Mass",
            /* 4.email */
            "Taurus69@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/157024_137966606260003_8049221_n.jpg?oh=86da533cfa44e87eeed74cd5c3204947&oe=5A4ED6F8',
            /* 8.image2 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/155586_131195643603766_8366265_n.jpg?oh=2e2b97677434125d601d60fa9999ab56&oe=5A3C8678',
          /* 9.image3 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/165355_136303249766432_4358068_n.jpg?oh=414f79b507f18b3cc23e3401a4ac98fb&oe=5A4A3D38',
          /* 10.image4 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/75342_129821747074489_7335949_n.jpg?oh=36a586775d84f3d0b8f799856490edfc&oe=5A42425F',
          /* 11.birthdate */
          '1950-09-03',
          /* 12.gender */
          '1',
          /* 13.tags */
          '/Fake/Gay/Ete/Lune/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam accumsan tempor pellentesque. Duis convallis arcu odio, ut pharetra justo euismod eget. Pellentesque lorem felis, hendrerit at consequat ut, volutpat sit amet ante. Curabitur est libero, suscipit ac sodales in, ornare quis ipsum. Sed lacus felis, molestie ac commodo id, hendrerit vel leo. Mauris urna purus, facilisis eu posuere sed, aliquam in nisi. Quisque in dignissim velit. Nulla vel neque vulputate, cursus erat non, rutrum turpis. Cras tellus mauris, efficitur id est vel, molestie placerat nunc. Donec mi augue, egestas vitae ullamcorper quis, feugiat nec tortor. Fusce ornare dolor molestie, aliquet quam sed, lobortis nisl.',
          /* 22.targetsexe */
          '3',
          /* 23.longitude */
          '39.56',
          /* 24.latitude */
          '5.678',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser Mass69 -> ', err);
  } else {
    console.log('Create Mass69');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, image3, image4,birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, '1')`,
          [
            /* 1.login */
            'Melissa47',
            /* 2.firstname*/
            "Melissa",
            /* 3.lastname */
            "Jenson",
            /* 4.email */
            "Jenson47@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://www.facebook.com/photo.php?fbid=161250740596968&set=a.115488838506492.19998.100001361297429&type=3&theater',
            /* 8.image2 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/196748_162582677130441_4894143_n.jpg?oh=5130c79acf761d3dcc6e5217794e6834&oe=5A4100AC',
          /* 9.image3 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/188622_162582260463816_7858430_n.jpg?oh=bf14313f3775c6b2a2693b4835fdaba8&oe=5A470B1A',
          /* 10.image4 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/200337_164056380316404_1092708_n.jpg?oh=0ccad6543c11790e599d563978e6eca3&oe=5A477ED5',
          /* 11.birthdate */
          '1978-09-03',
          /* 12.gender */
          '2',
          /* 13.tags */
          '/Fake/Peuplier/Ete/Lune/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam accumsan tempor pellentesque. Duis convallis arcu odio, ut pharetra justo euismod eget. Pellentesque lorem felis, hendrerit at consequat ut, volutpat sit amet ante. Curabitur est libero, suscipit ac sodales in, ornare quis ipsum. Sed lacus felis, molestie ac commodo id, hendrerit vel leo. Mauris urna purus, facilisis eu posuere sed, aliquam in nisi. Quisque in dignissim velit. Nulla vel neque vulputate, cursus erat non, rutrum turpis. Cras tellus mauris, efficitur id est vel, molestie placerat nunc. Donec mi augue, egestas vitae ullamcorper quis, feugiat nec tortor. Fusce ornare dolor molestie, aliquet quam sed, lobortis nisl.',
          /* 22.targetsexe */
          '1',
          /* 23.longitude */
          '47.56',
          /* 24.latitude */
          '5.678',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser Jenson47 -> ', err);
  } else {
    console.log('Create Jenson47');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, '1')`,
          [
            /* 1.login */
            'ElDuduSurita69',
            /* 2.firstname*/
            "Dudu",
            /* 3.lastname */
            "Surita",
            /* 4.email */
            "ElDuduSurita69@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-1/c24.167.169.169/553399_450972288269652_728150970_n.jpg?oh=ccd92607c4b6569593b800ef90b36ed1&oe=5A4A8136',
          /* 11.birthdate */
          '1998-09-03',
          /* 12.gender */
          '1',
          /* 13.tags */
          '/Fake/Charo/Ete/Lune/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Cherche jeune demoisselle !!!!',
          /* 22.targetsexe */
          '2',
          /* 23.longitude */
          '43.56',
          /* 24.latitude */
          '0.5678',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser ElDuduSurita69 -> ', err);
  } else {
    console.log('Create ElDuduSurita69');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, image3, image4, image5, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,'1')`,
          [
            /* 1.login */
            'Asheley88',
            /* 2.firstname*/
            "Asheley",
            /* 3.lastname */
            "Sersi",
            /* 4.email */
            "Asheley88@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/319249_183855651682455_737458_n.jpg?oh=1bd10e1f3a146deae87f204482b31e82&oe=5A435414',
            /* 8.image2 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/316598_186433091424711_1424421_n.jpg?oh=a024a3935a24d61ea0d909e94e7d223f&oe=5A3DE39F',
          /* 9.image3 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/313625_186364684764885_6932648_n.jpg?oh=765993a858602615f4f85b65c295524a&oe=5A4E750A',
          /* 10.image4 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/304780_184996564901697_4302417_n.jpg?oh=82ec60424602fd7c5d50d723eaeff73e&oe=5A493FBE',
          /* image5 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/298133_187171458017541_6891363_n.jpg?oh=5c5f2bca2d6937f9267cade3efc9939d&oe=5A3D383B',
          /* 11.birthdate */
          '1938-09-03',
          /* 12.gender */
          '2',
          /* 13.tags */
          '/Fake/Peuplier/Ete/Jeune/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Cougare mais ca se voit pas ',
          /* 22.targetsexe */
          '3',
          /* 23.longitude */
          '46.56',
          /* 24.latitude */
          '2.8',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser Asheley88 -> ', err);
  } else {
    console.log('Create Asheley88');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, image3, image4, image5, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,'1')`,
          [
            /* 1.login */
            'LaZoeKetecalienta12',
            /* 2.firstname*/
            "Zoe",
            /* 3.lastname */
            "Ketecalienta",
            /* 4.email */
            "ZoeKete12@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/574829_322892144447006_1673497885_n.jpg?oh=559f046fb4c68b232cf7da849975c4d8&oe=5A4E852E',
            /* 8.image2 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/550934_333903040012583_1112888362_n.jpg?oh=ece3433d71f28c5e223994aa8d33f7e3&oe=5A5B5858',
          /* 9.image3 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/526790_338924666177087_1124460901_n.jpg?oh=0c5f86b13a62a921647e2b33a9cd77be&oe=5A550FEA',
          /* 10.image4 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/165896_339664699436417_1887909089_n.jpg?oh=893fbde1629f92bf93ea1e2918108f3e&oe=5A56C5EB',
          /* image5 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/166053_339078062828414_1604883482_n.jpg?oh=780555986b311dfe22b9efd57f73f101&oe=5A60DBA0',
          /* 11.birthdate */
          '1995-09-03',
          /* 12.gender */
          '2',
          /* 13.tags */
          '/Fake/Lune/Ete/Jeune/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Cougare mais ca se voit pas ',
          /* 22.targetsexe */
          '2',
          /* 23.longitude */
          '46.56',
          /* 24.latitude */
          '1.58',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser LaZoeKetecalienta12 -> ', err);
  } else {
    console.log('Create LaZoeKetecalienta12');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, image3, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,'1')`,
          [
            /* 1.login */
            'Kourtney69',
            /* 2.firstname*/
            "Kourtney",
            /* 3.lastname */
            "Thomson",
            /* 4.email */
            "Kourtney69@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/423790_265774080161193_1941461497_n.jpg?oh=98c1b0a013b1554a8f025f2f541c766f&oe=5A135613',
            /* 8.image2 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/208075_138892506182685_4338476_n.jpg?oh=10e769a420388d87bd55247cba3cd240&oe=5A5B0E14',
          /* 9.image3 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/216583_138723516199584_7761099_n.jpg?oh=54d08dc0954e255438df7fb5dd4977a2&oe=5A3C4EAC',
          /* 11.birthdate */
          '1910-09-03',
          /* 12.gender */
          '2',
          /* 13.tags */
          '/Fake/Love/Ete/Jeune/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Love Love Love  ',
          /* 22.targetsexe */
          '3',
          /* 23.longitude */
          '46.646465',
          /* 24.latitude */
          '2.56464',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser Kourtney69 -> ', err);
  } else {
    console.log('Create Kourtney69');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,'1')`,
          [
            /* 1.login */
            'LaKetecalienta12',
            /* 2.firstname*/
            "Lea",
            /* 3.lastname */
            "Ketecalienta",
            /* 4.email */
            "Ketecalienta654@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/430002_265762563495678_2051917794_n.jpg?oh=eb1853227a59537d74288ca15851bc1f&oe=5A4D02BD',
          /* 11.birthdate */
          '1994-09-03',
          /* 12.gender */
          '2',
          /* 13.tags */
          '/Fake/Lune/Ete/Jeune/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Cougare mais ca se voit pas ',
          /* 22.targetsexe */
          '3',
          /* 23.longitude */
          '47.56',
          /* 24.latitude */
          '1.5856',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser LaKetecalienta12 -> ', err);
  } else {
    console.log('Create LaKetecalienta12');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, image3, image4, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,'1')`,
          [
            /* 1.login */
            'Andjela95',
            /* 2.firstname*/
            "Andjela",
            /* 3.lastname */
            "Dincic",
            /* 4.email */
            "ZoeDincic12@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/66875_114713585256124_5357108_n.jpg?oh=404365ea32e19dc912bb8ef826c2e581&oe=5A400F43',
            /* 8.image2 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/44339_101961193198030_4143542_n.jpg?oh=f82e93bd9cec9b3f3fc62aef309eb84d&oe=5A4E247F',
          /* 9.image3 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/40164_101891486538334_755460_n.jpg?oh=e236e81518cc310b9a34bf48c09ac254&oe=5A52550E',
          /* 10.image4 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/45391_101702863223863_5862420_n.jpg?oh=2735f3a071dc157e0fd9ac00786f9de9&oe=5A4DC0CE',

          /* 11.birthdate */
          '1910-09-03',
          /* 12.gender */
          '2',
          /* 13.tags */
          '/Fake/Lune/Ete/Jeune/Belgrade/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'A l ancienne !!!!1 ',
          /* 22.targetsexe */
          '1',
          /* 23.longitude */
          '46.56',
          /* 24.latitude */
          '1.58',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser Andjela95 -> ', err);
  } else {
    console.log('Create Andjela95');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, image2, image3, image4, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,'1')`,
          [
            /* 1.login */
            'Tansel65',
            /* 2.firstname*/
            "Tansel",
            /* 3.lastname */
            "Erdik",
            /* 4.email */
            "Zoseuhroc12@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t31.0-1/c160.0.960.960/p960x960/132225_1643646485617_2888371_o.jpg?oh=04aea4d2161e9a2aace1d5a66ec23d88&oe=5A5E2221',
            /* 8.image2 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/16002754_10209948422161746_2772342518795646237_n.jpg?oh=d0c625d7499d55ac61ac8c997d292954&oe=5A5432FE',
          /* 9.image3 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/15966107_10209914036742132_4220328784988354805_n.jpg?oh=332b3b835121553c8622ecbe61ab924e&oe=5A491DD8',
          /* 10.image4 */
          'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/15977156_10209908015551606_4610443827545308014_n.jpg?oh=25c834e1a0b202e37765aceac7c96891&oe=5A4E7D50',

          /* 11.birthdate */
          '1945-09-03',
          /* 12.gender */
          '1',
          /* 13.tags */
          '/Fake/Sun/Ete/Hayer/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'Ninja du Froid !!!!1 ',
          /* 22.targetsexe */
          '2',
          /* 23.longitude */
          '46.57531',
          /* 24.latitude */
          '3.6579',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser Tansel65 -> ', err);
  } else {
    console.log('Create Tansel65');
  }
})

con.query(`INSERT INTO users (login, firstname, lastname, email, password, token, image1, birthdate , gender, tags, mylike, liked, matchs, notif, myblock, blocked, usr_report, bio, targetsexe, latitude, longitude, status)
            VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,'1')`,
          [
            /* 1.login */
            'HendrikBG92',
            /* 2.firstname*/
            "David",
            /* 3.lastname */
            "Hendrik",
            /* 4.email */
            "Hendrik54@gmail.fr",
            /* 5.password */
            password_fake,
            /* 6.token */
            "",
            /* 7.image1*/
            'https://scontent-cdg2-1.xx.fbcdn.net/v/t1.0-9/26480_101507543219618_925785_n.jpg?oh=b05f4e7f66aca44de3d92530381128c0&oe=5A47A001',
          /* 11.birthdate */
          '1997-06-03',
          /* 12.gender */
          '1',
          /* 13.tags */
          '/Fake/Lune/BeauGosse/Jeune/',
          /* 14.mylike */
          '[]',
          /* 15.liked */
          '[]',
          /* 16.matchs */
          '[]',
          /* 17.notif */
          '[]',
          /* 18.blocked */
          '[]',
          /* 19.myblock */
          '[]',
          /* 20.usr_report */
          '[]',
          /* 21.bio */
          'SISI BG ',
          /* 22.targetsexe */
          '3',
          /* 23.longitude */
          '47.56',
          /* 24.latitude */
          '1.5856',
          /* 25.status*/
          '1'],
(err) => {
  if (err) {
    console.error('error setupUser HendrikBG92 -> ', err);
  } else {
    console.log('Create HendrikBG92');
  }
})

con.end()
