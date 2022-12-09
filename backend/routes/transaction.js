const express = require('express');
const router = express.Router();
const transaction = require('../models/transaction_model');

router.get('/:id?',
function (request, response) {
  if (request.params.id) {
    transaction.getById(request.params.id, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    transaction.getAll(function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

router.get('/fivetransactions/:id', function (request, response) {
const id = request.params.id;
transaction.getFiveTransactions(id, function (err, dbResult) {
  if (err) {
    response.json(err);
  }
  else {
    response.json(dbResult);
  }
})

});

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


router.post('/',
function (request, response) {
  transaction.add(request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(request.body);
      }
    });
  });


router.delete('/:id',
  function (request, response) {
    transaction.delete(request.params.id, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });


router.put('/:id',
  function (request, response) {
    transaction.update(request.params.id, request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });

module.exports = router;