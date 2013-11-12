// import
var EJDB = require('ejdb')
  , path = require('path')
  , hljs = require('highlight.js');

// objects
var db = EJDB.open(path.join(__dirname, 'data'));
console.log('Datebase loaded successfully.');

// function
var highlight = function (data) {
  var result;
  try {
    result = hljs.highlight(data.language, data.content).value;
  } catch (err) {
    result = hljs.highlightAuto(data.content).value;
  }
  return result;
};

// get(paste_name, callback(err, data))
exports.get = function (paste_name, callback) {
  db.findOne(paste_name, function (err, obj) {
    if (err) {
      callback(err);
    } else if (!obj) {
      callback(Error('Paste not found'));
    } else {
      callback(undefined, obj);
    }
  });
};

// put(data, callback(err))
exports.put = function (paste_data, callback) {
  var paste_name = paste_data.shortname;
  paste_data.rendered = highlight(paste_data);

  db.count(paste_name, function (err, count) {
    if (err) {
      callback(err);
    } else if (count !== 0) {
      callback(Error('The paste named ' + paste_name + ' is already exists.'));
    } else {
      db.save(paste_name, paste_data, function (err, obj_id) {
        if (err) {
          callback(err);
        } else {
          callback(undefined);
        }
      });
    }
  });
};