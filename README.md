# node-blake2

Blake2 node binding.

# Installation

`npm install node-blake2`

# Usage
Simple usage
```javascript
var blake2 = require('node-blake2') ;
var filename = 'dummy' ;
var hash_b = blake2.blake2b(filename) ;
var hash_s = blake2.blake2s(filename) ;
var hash_bp = blake2.blake2bp(filename) ;
var hash_sp = blake2.blake2sp(filename) ;
```

