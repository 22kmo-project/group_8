const express = require('express');
const useraccount = require('../models/useraccount_model');
const router = express.Router();

//uid on user id ja aid on account id
router.post('/',
function (request, response) {
    useraccount.getIdAccount(request.body.id_user, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
});

router.get('/:uid?,:aid?',
 function(request, response) {
  if (request.params.uid, request.params.aid) {
    useraccount.getByUserAccountId(request.params.uid, request.params.aid, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  }/* else if (request.params.uid){
	useraccount.getByUserId(request.params.uid, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
  } else if (request.params.aid){
	useraccount.getByAccountId(request.params.aid, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult[0]);
      }
    });
}*/ 
  else {
    useraccount.getAll(function(err, dbResult) {
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
  useraccount.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.delete('/:uid,:aid', 
function(request, response) {
    useraccount.delete(request.params.uid, request.params.aid, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put('/:uid,:aid', 
function(request, response) {
    useraccount.update(request.params.uid, request.params.aid, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


module.exports = router;