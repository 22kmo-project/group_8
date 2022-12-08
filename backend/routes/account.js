const express = require('express');
const router = express.Router();
const account = require('../models/account_model');

router.get('/:id?',
  function (request, response) {
    if (request.params.id) {
      account.getById(request.params.id, function (err, dbResult) {
        if (err) {
          response.json(err);
        } else {
          response.json(dbResult[0]);
        }
      });
    } else {
      account.getAll(function (err, dbResult) {
        if (err) {
          response.json(err);
        } else {
          response.json(dbResult);
        }
      });
    }
  });

router.get('/:id?',
  function (request, response) {
    account.getAccountID(request.params.id, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {z
        response.json(dbResult[0]);
      }
    });
  });



router.post('/',
  function (request, response) {
    account.add(request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(request.body);
      }
    });
  });

router.delete('/:id',
  function (request, response) {
    account.delete(request.params.id, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });

router.put('/:id',
  function (request, response) {
    account.update(request.params.id, request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });

  router.put('/balance/:id',
  function (request, response) {
    account.balance(request.params.id, request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });

  router.put('/creditlimit/:id',
  function (request, response) {
    account.creditlimit(request.params.id, request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });

router.post('/idaccount?',
  function (request, response) {
    account.idaccount(request.params.id_card, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  });

router.post('/owner',
  function (request, response) {
    account.owner(request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  });
module.exports = router;