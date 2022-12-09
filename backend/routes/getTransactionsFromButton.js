const express = require('express');
const router = express.Router();
const transaction = require('../models/transaction_model');



router.get('/:id/:idTrans',
 function(request, response) {
  const idTrans = Number(request.params.idTrans);
  transaction.getTransactionsFromButton(request.params.id, idTrans, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  })
 });

module.exports=router;