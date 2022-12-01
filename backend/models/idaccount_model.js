const db = require('../database');

const idaccount={
    getIdAccount: function (id_card, callback) {
        return db.query('select id_account from account where id_card = ?', [id_card], callback);
      },
};

module.exports = idaccount;

