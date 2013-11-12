// import
var express = require('express')
  , path = require('path')
  , router = require(path.join(__dirname, 'router.js'));

// objects
var app = express();

// config
app.set('port', process.env.PORT || 80);
app.use(express.favicon());
app.use(express.json());
app.use(express.urlencoded());
app.use(express.static(path.join(__dirname, 'static')));
console.log('Configured successfully.');

// route
router.setup(app);
console.log('Router settled up successfully.');

// setup server
app.listen(app.get('port'));
console.log('Pastebin is running on', app.get('port') + '.');
