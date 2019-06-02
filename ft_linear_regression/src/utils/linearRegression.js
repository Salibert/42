const norm = (data) => {
    let nData = []
    let max = 0
    data.forEach(element => { if (element > max) {  max = element } })
    data.map(element => nData.push(element/max))
    return { data: nData, max }
}

const costFunc = (dataX, dataY) => {
    let cost = 0
    let len = Object.keys(dataX).length
    for (let i=0; i< len; i++) {
        cost += Math.pow((dataY[i] - hypothesis(dataX[i])), 2)
    }
    return (cost/len)
}

const learn = (x, y, alpha) => {
    let thetaSum = [0, 0]
    let  theta = [0, 0]
    let lenDataSet = Object.keys(x).length
    for (let i = 0; i < x.length; i++) {
        thetaSum[0] += hypothesis(x[i]) - y[i]
        thetaSum[1] += (hypothesis(x[i]) - y[i]) * x[i]
    }
    theta[0] = global.data.theta[0] - (alpha / lenDataSet) * thetaSum[0]
    theta[1] = global.data.theta[1] - (alpha / lenDataSet) * thetaSum[1]
    return [ theta, costFunc(x, y) ]
}

const hypothesis = (x) => global.data.theta[0] + (global.data.theta[1] * x)

const iter = (dataSet, alpha, maxIter, precision) => {
    let nX = norm(dataSet[0])
    let nY = norm(dataSet[1])
    let theta, cost
    for (let i = 0; i < maxIter; i++) {
        [ theta, cost ] = learn(nX.data, nY.data, alpha)
        if (Math.abs(global.data.theta[0] - theta[0]) <= precision && Math.abs(global.data.theta[1] - theta[1]) <= precision) {
            break
        }
        global.data.theta = theta
        global.data.cost = cost
    }
    global.data.theta[0] = global.data.theta[0] * nY.max
    global.data.theta[1] = global.data.theta[1] * nY.max / nX.max
}

export { hypothesis, learn, iter, costFunc }