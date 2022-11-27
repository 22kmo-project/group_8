const express = require('express');
const router = express.Router();
const user_account = require('../models/user_account_model');

//uid on user id ja aid on account id
router.get('/:uid?,:aid?',
 function(request, response) {
  if (request.params.uid, request.params.aid) {
    user_account.getByUserAccountId(request.params.uid, request.params.aid, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  }/* else if (request.params.uid){
	user_account.getByUserId(request.params.uid, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  } else if (request.params.aid){
	user.getByAccountId(request.params.aid, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
}*/ 
  else {
    user_account.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

router.post('/', 
function(request, response) {
  user_account.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.delete('/:uid,:aid', 
function(request, response) {
    user_account.delete(request.params.uid, request.params.aid, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put('/:uid,:aid', 
function(request, response) {
    user_account.update(request.params.uid, request.params.aid, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;