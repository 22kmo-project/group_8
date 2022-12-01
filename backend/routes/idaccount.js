const express = require('express');
const router = express.Router();
const idaccount = require('../models/idaccount_model');

router.post('/',
function (request, response) {
    idaccount.getIdAccount(request.body.id_card, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
});

    module.exports = router;