module.exports = (router) => {
  require('./routes/Usr.js')(router),
  require('./routes/match.js')(router)
}
