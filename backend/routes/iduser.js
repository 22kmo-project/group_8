const express = require('express');
const router = express.Router();
const iduser = require('../models/iduser_model');

router.post('/',
function (request, response) {
    iduser.getIdUser(request.body.id_user, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
});

    module.exports = router;