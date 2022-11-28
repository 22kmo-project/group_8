const db = require('../database');

//uid on user id ja aid on account id
const user_account = {
    getByUserAccountId: function(uid, aid, callback) {
        return db.query('select * from user_account where id_user=? AND id_account=?', [uid, aid], callback);
      }/*,
      getByUserId: function(uid, callback) {
    return db.query('select * from user_account where id_user=?', [uid], callback);
  },
  getByAccountId: function(aid, callback) {
    return db.query('select * from user_account where id_account=?', [aid], callback);
  }*/,
  getAll: function(callback) {
    return db.query('select * from user_account', callback);
  },


  add: function(add_data, callback) {
    return db.query(
      'insert into user_account (id_user, id_account, account_owner) values(?,?,?)',
      [add_data.id_user, add_data.id_account, add_data.account_owner],
      callback
    );
  },
   
  delete: function(uid, aid, callback) {
    return db.query('delete from user_account where id_user=? AND id_account=?', [uid, aid], callback);
  },

  update: function(uid, aid, update_data, callback) {
    return db.query(
      'update user_account set id_user=?, id_account=?, account_owner=? where id_user=? AND id_account=?',
      [update_data.id_user, update_data.id_account, update_data.account_owner, uid, aid],
      callback
    );
  }
};
module.exports = user_account;
