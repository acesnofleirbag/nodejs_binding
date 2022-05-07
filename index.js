const native = require('./build/Release/bind');

const sum = native.bindSum(3, 2);

console.log('>>', sum);
