const db = require('../database');

//uid on user id ja aid on account id
const useraccount = {
  getIdAccount: function (id_card, callback) {
    return db.query('select id_account from user_account where id_user = ?', [id_card], callback);
  },
  getByUserAccountId: function (uid, aid, callback) {
    return db.query('select * from user_account where id_user=? AND id_account=?', [uid, aid], callback);
  },
  getAll: function (callback) {
    return db.query('select * from user_account', callback);
  },

  add: function (add_data, callback) {
    return db.query(
      'insert into user_account (id_user, id_account) values(?,?)',
      [add_data.id_user, add_data.id_account],
      callback
    );
  },

  delete: function (uid, aid, callback) {
    return db.query('delete from user_account where id_user=? AND id_account=?', [uid, aid], callback);
  },

  update: function (uid, aid, update_data, callback) {
    return db.query(
      'update user_account set id_user=?, id_account=? where id_user=? AND id_account=?',
      [update_data.id_user, update_data.id_account,  uid, aid],
      callback
    );
  }
};

module.exports = useraccount;