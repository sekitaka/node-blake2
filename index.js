var blake2 = require('./build/Release/blake2') ;
module.exports.blake2b = function(filename) {
    return blake2.blake2(filename,'blake2b') ;
}
module.exports.blake2s = function(filename) {
    return blake2.blake2(filename,'blake2s') ;
}
module.exports.blake2bp = function(filename) {
    return blake2.blake2(filename,'blake2bp') ;
}
module.exports.blake2sp = function(filename) {
    return blake2.blake2(filename,'blake2sp') ;
}
