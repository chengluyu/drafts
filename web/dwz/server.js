// import
var levelup = require('level')
  , express = require('express')
  , fs = require('fs')
  , url = require('url');

// objects
var db = levelup('./database')
  , app = express();

// functions
var render_error = function (err, res) {
  res.writeHeader(404, { "Content-Type": "text/html" });
  res.write(err.toString());
  res.end();
};

var render_text = function (text, res) {
  res.writeHeader(200, { "Content-Type": "text/html" });
  res.write(text);
  res.end();
};

var format_url = function (website) {
  if (!website.match(/$\w+\:\/\//))
    website = 'http://' + website;
  return website;
};

// config
app.use(express.json());
app.use(express.urlencoded());

// router
app.get('/', function (req, res) {
  fs.readFile('./index.html', 'utf8', function (err, html) {
    if (err) {
      render_error(err, res);
    } else {
      render_text(html, res);
    }
  });
});

app.post('/', function (req, res) {
  var shortname = req.body.shortname
    , website = format_url(req.body.website);

  console.log('Add:', shortname, '==>', website);

  db.put(shortname, website, function (err) {
    if (err) {
      render_error(err, res);
    } else {
      render_text('Shorted:<a href="/' + shortname + '">Click here.</a>', res);
    }
  });
});

app.get('/:name', function (req, res) {
  var name = req.params.name;

  db.get(name, function (err, value) {
    if (err) {
      render_error(err, res);
    } else {
      res.redirect(value);
    }
  });
});

// startup server
app.listen(80);