var fs = require('fs');
var path = require('path');
var util = require('util');

var support_file_extname = {
  '.md': true,
  '.mdown': true,
  '.markdn': true,
  '.markdown': true,
  available: function (extname) {
    return typeof this[extname] === 'boolean' && this[extname];
  }
};


var get_full_path = function (file_name) {
  if (typeof file_name !== 'string') {
    throw new Error('Argument type mismatch, should be string: ' +
        typeof file_name);
    return;
  } if (file_name === '') {
    throw new Error('Empty file name: ' + file_name);
    return;
  }
  // test if it's only a file_name
  if (/^[^\\\/]+$/.test(file_name)) {
    file_name = path.join(__dirname, 'hyde', 'posts', file_name);
  }

  // test if configuration file is available
  var extname = path.extname(file_name);

  if (support_file_extname.available(extname)) {
    file_name = file_name.substring(0, file_name.length - extname.length);
    file_name += '.json';
  } else if (extname === '') {
    file_name += '.json';
  } else if (extname !== '.json') {
    throw new Error('Error file type: ' + file_name);
    return;
  }
  return file_name;
};

var update = function (file_name, property, value) {
  var config;

  try {
    // get full file name
    file_name = get_full_path(file_name);

    if (!fs.existsSync(file_name)) {
      config = { };
    } else {
      if (!fs.statSync(file_name).isFile()) {
        throw new Error('Not a file: ' + file_name);
        return;
      }
      // parse JSON file
      config = JSON.parse(fs.readFileSync(file_name, 'utf8'));
    }
  } catch (error) {
    console.log(error);
    return;
  }

  if (property && value) {
    config[property.toLowerCase()] = value;
  }

  fs.writeFileSync(file_name, JSON.stringify(config), 'utf8');
};

var info = function (file_name, property) {
  var config;

  try {
    // get full file name
    file_name = get_full_path(file_name);

    if (!fs.existsSync(file_name)) {
      throw new Error('File does not exists: ' + file_name);
      return;
    }
    if (!fs.statSync(file_name).isFile()) {
      throw new Error('Not a file: ' + file_name);
      return;
    }
    // parse JSON file
    config = JSON.parse(fs.readFileSync(file_name, 'utf8'));
  } catch (error) {
    console.log(error);
    return;
  }

  if (property)
    console.log(config[property.toLowerCase()]);
  else
    console.log(config);
};

if (process.argv[2] === 'info')
  info(process.argv[3], process.argv[4]);
else if (process.argv[2] === 'update')
  update(process.argv[3], process.argv[4], process.argv.slice(5));