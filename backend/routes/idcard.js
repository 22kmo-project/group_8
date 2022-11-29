
const express = require('express');
const router = express.Router();
const idcard = require('../models/idcard_model');

router.post('/',
    function (request, response) {
        idcard.getCardId(request.body.card_number, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });

module.exports = router;