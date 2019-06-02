import request from 'superagent'

export function callApi (endpoint, method = 'get', body) {
  return new Promise((resolve, reject) => {
    if (method === 'post') {
      request.post(`http://localhost:5000/${endpoint}`)
        .send(body)
        .set('Accept', 'application/json')
        .then((res) => {
          const body = JSON.parse(res.text)
          resolve(body)
        })
        .catch(e => {
          reject(e.message)
        })
    }
    if (method === 'get') {
      request.get(`http://localhost:5000/${endpoint}`)
        .set('Accept', 'application/json')
        .then((res) => {
          const body = JSON.parse(res.text)
          resolve(body)
        })
        .catch(e => {
          reject(e.message)
        })
    }

    if (method === 'put') {
      request.put(`http://localhost:5000/${endpoint}`)
        .set('Accept', 'application/json')
        .then((res) => {
          const body = JSON.parse(res.text)
          resolve(body)
        })
        .catch(e => {
          reject(e.message)
        })
    }
    if (method === 'delete') {
      request.delete(`http://localhost:5000/${endpoint}`)
        .set('Accept', 'application/json')
        .then((res) => {
          resolve({})
        })
        .catch(e => {
          reject(e.message)
        })
    }
    if (method === 'image') {
      request.post(`http://localhost:5000/${endpoint}`)
        .send(body)
        .then((res) => {
          const body = JSON.parse(res.text)
          resolve(body)
        })
        .catch(e => {
          reject(e.message)
        })
    }
  })
}
