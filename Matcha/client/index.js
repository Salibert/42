
import { createStore, applyMiddleware, combineReducers, compose } from 'redux'
import { syncHistoryWithStore, routerReducer } from 'react-router-redux'
import { Router, Route, browserHistory, Redirect } from 'react-router'
import NotFound from './components/NotFound'
import LoginContainer from './components/User/login'
import SignupContainer from './components/User/SignUp'
import ValideAccount from './components/User/ValideAccount'
import ForGetPassword from './components/User/ForGetPassword'
import HelpUser from './components/User/HelpUser'
import socketIoMiddleWare from './middleware/index.js'
import { CookiesProvider } from 'react-cookie'
import { Provider } from 'react-redux'
import ReactDom from 'react-dom'
import userReducer from './reducers'
import thunkMiddleWare from 'redux-thunk'
import React from 'react'
import { reducer as formReducer } from 'redux-form'
import Profile from './components/User'
import home from './components/Home'
import Header from './components/Header'
import { Cookies } from 'react-cookie'
import { MuiThemeProvider, getMuiTheme } from 'material-ui/styles'
import { fade } from 'material-ui/utils/colorManipulator'
import io from 'socket.io-client'
import injectTapEventPlugin from 'react-tap-event-plugin'
import {
  grey600,
  grey100,
  grey300,
  grey500,
  white,
  darkBlack,
  fullBlack,
} from 'material-ui/styles/colors'
import EnsureLoggedInContainer from './service/isLogin'

injectTapEventPlugin()

const muiTheme = getMuiTheme({
  palette: {
    primary1Color: '#3e4eb7', // dark blue
    primary2Color: '#3e4eb7', // dark blue
    primary3Color: '#3e4eb7',
    accent1Color: '#ff3b7f', // fancy pink
    accent2Color: grey100,
    accent3Color: grey500,
    textColor: '#000000',
    alternateTextColor: white,
    alternateTextColor2: '#ff3b7f',
    canvasColor: '#fff7f7',
    borderColor: grey300,
    disabledColor: fade(darkBlack, 0.3),
    pickerHeaderColor: '#3e4eb7', // dark blue
    clockCircleColor: fade(darkBlack, 0.07),
    shadowColor: fullBlack,
  },
  fontFamily: 'Roboto, sans-serif',
  raisedButton: {
    fontSize: '1.1em',
    fontWeight: 100,
    textTransform: 'capitalize',
  },
  flatButton: {
    fontSize: '1.1em',
    fontWeight: 100,
    textTransform: 'capitalize',
  },
  userAgent: false,
})

require('babel-core/register')
require('babel-polyfill')

const configureStore = (userReducer) => createStore(
  combineReducers({
    routing: routerReducer,
    session: userReducer,
    form: formReducer,
  }),
  composeEnhancers(
    applyMiddleware(
      socketIoMiddleWare(socket),
      thunkMiddleWare
    ))
)

const socket = io('http://localhost:5000')

const composeEnhancers = window.__REDUX_DEVTOOLS_EXTENSION_COMPOSE__ || compose
const store = configureStore(userReducer)
const history = syncHistoryWithStore(browserHistory, store)
const cookies = new Cookies()

ReactDom.render((
  <Provider store={store}>
    <div style={{ color: muiTheme.palette.textColor, height: '100vh' }}>
      <MuiThemeProvider muiTheme={muiTheme}>
        <Router history={history}>
          <Route path='/' component={Header}>
            <Route path='/ForgetMyPassword' component={ForGetPassword} />
            <Route path='/ValideAccount' component={ValideAccount} />
            <Route path='/HelpUser' component={HelpUser} />
            <Route path='/signup' component={SignupContainer} />
            <Route path='/signin' component={LoginContainer} />
            <CookiesProvider>
              <Route component={EnsureLoggedInContainer}>
                <Route path='/profile' component={Profile} />
                <Route path='/home' component={home} />
              </Route>
            </CookiesProvider>
            <Route path='*' component={NotFound} />
          </Route>
        </Router>
      </MuiThemeProvider>
    </div>
  </Provider>
), document.getElementById('React-starterKit'))
