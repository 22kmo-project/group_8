const db = require('../database');

const iduser={
    getIdUser: function (id_user, callback) {
        return db.query('select id_user from account where id_account = ?', [id_user], callback);
      },
};

module.exports = iduser;