const db = require('../database');

const account = {
  getById: function (id, callback) {
    return db.query('select * from account where id_account=?', [id], callback);
  },

  owner: function (id,callback) {
    return db.query('select account_owner from account where id_account=?', [id], callback);
  },

  getAll: function (callback) {
    return db.query('select * from account', callback);
  },
  add: function (add_data, callback) {
    return db.query(
      'insert into account (account_type,balance,account_owner, id_card) values(?,?,?,?)',
      [add_data.account_type, add_data.balance, add_data.account_owner, add_data.id_card]);
  },
  delete: function (id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      'update account set account_type=?,balance=?, account_owner=?, id_card=? where id_account=?',
      [update_data.account_type, update_data.balance, update_data.account_owner, updata_data.id_card, id]);
  },


};
module.exports = account;