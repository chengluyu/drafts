// import
var fs = require('fs')
  , path = require('path')
  , util = require('util')
  , dot = require('dot')
  , paste = require(path.join(__dirname, 'paste.js'))
  , crypto = require('crypto');

// constant
var filename = {
  index: path.join(__dirname, 'pages', 'index.html'),
  view: path.join(__dirname, 'pages', 'view.html'),
  error: path.join(__dirname, 'pages', 'error.html'),
};
var view_fn = dot.template(fs.readFileSync(filename.view))
  , error_fn = dot.template(fs.readFileSync(filename.error));

// function
var write_html = function (text, res) {
  res.writeHeader(200, { "Content-Type": "text/html" });
  res.write(text);
  res.end();
};

var write_text = function (text, res) {
  res.writeHeader(200, { "Content-Type": "text/plain" });
  res.write(text);
  res.end();
};

var render_error = function (err, res) {
  res.writeHeader(404, { "Content-Type": "text/html" });
  res.write(error_fn({ 'error': err.toString() }));
  res.end();
};

exports.setup = function (app) {
  app.get('/', function (req, res) {
    fs.readFile(filename.index, 'utf8', function (err, html) {
      write_html(html, res);
    });
  });

  app.post('/', function (req, res) {
    var data = req.body;

    if (data.content.length === 0) {
      render_error('Paste content cannot be empty.', res);
      return;
    }

    data.title = data.title || 'Untitled';
    data.author = data.author || 'Anonymous';
    if (data.shortname.length === 0) {
      data.shortname = crypto.randomBytes(8).toString('hex');
    }

    paste.put(data, function (err) {
      if (err) {
        render_error(err, res);
      } else {
        res.redirect('/' + data.shortname);
      }
    });
  });

  app.post('/go', function (req, res) {
    if (!req.body.paste_id) {
      res.redirect('/');
    } else {
      res.redirect('/' + req.body.paste_id);
    }
  });

  app.get('/:paste_name', function (req, res) {
    var paste_name = req.params.paste_name;

    paste.get(paste_name, function (err, data) {
      if (err) {
        render_error(err, res);
      } else {
        write_html(view_fn(data), res);
      }
    });
  });

  app.get('/raw/:paste_name', function (req, res) {
    var paste_name = req.params.paste_name;

    paste.get(paste_name, function (err, data) {
      if (err) {
        render_error(err, res);
      } else {
        write_text(data.content, res);
      }
    });
  });
};