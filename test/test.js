// Should be installed b2sum .
var blake2 = require('../index.js') ;
var file = '/tmp/dummy' ; // dummy file
var exec = require('child_process').exec ;
var assert = require('assert') ;
exec('b2sum -a blake2b ' + file , function(err,stdout,stderr) {
    var hash1 = blake2.blake2b(file) ;
    var hash2 = getHash(stdout) ;
    assert.equal(hash1,hash2) ;
    console.log('black2b ok') ;
}) ;
exec('b2sum -a blake2s ' + file , function(err,stdout,stderr) {
    var hash1 = blake2.blake2s(file) ;
    var hash2 = getHash(stdout) ;
    assert.equal(hash1,hash2) ;
    console.log('black2s ok') ;
}) ;
exec('b2sum -a blake2bp ' + file , function(err,stdout,stderr) {
    var hash1 = blake2.blake2bp(file) ;
    var hash2 = getHash(stdout) ;
    assert.equal(hash1,hash2) ;
    console.log('black2bp ok') ;
}) ;
exec('b2sum -a blake2sp ' + file , function(err,stdout,stderr) {
    var hash1 = blake2.blake2sp(file) ;
    var hash2 = getHash(stdout) ;
    assert.equal(hash1,hash2) ;
    console.log('black2sp ok') ;
}) ;

function getHash(str) {
    //console.log('"' + str + '"' ) ;
    var idx = str.indexOf(' ') ;
    var ret = str.substring(0,idx) ;
    //console.log('"' + ret + '"' ) ;
    return ret ;
}

