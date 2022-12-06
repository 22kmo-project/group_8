const db = require('../database');

const account = {
  getById: function (id, callback) {
    return db.query('select * from account where id_account=?', [id], callback);
  },

  getBalance: function (id, callback) {
    return db.query('select balance from account where id_account=?', [id], callback);
  },
  getAccountOwner: function (id, callback) {
    return db.query('select account_owner from account where id_account=?', [id], callback);
  },

  getAll: function (callback) {
    return db.query('select * from account', callback);
  },
  add: function (add_data, callback) {
    return db.query(
      'insert into account (account_type,balance,id_card, id_user, account_owner, credit_limit) values(?,?,?,?,?,?)',
      [add_data.account_type, add_data.balance, add_data.id_card, add_data.id_user, add_data.account_owner, add_data.credit_limit], callback);
  },
  delete: function (id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      'update account set account_type=?,balance=?, id_card=?, id_user=?,account_owner=?, credit_limit=? where id_account=?',
      [update_data.account_type, update_data.balance, update_data.id_card, update_data.id_user, update_data.account_owner, update_data.credit_limit, id],callback);
  },

  balance: function (id, update_data, callback) {
    return db.query(
      'update account set balance=? where id_account=?',
      [update_data.balance,id],callback);
  },

  creditlimit: function(id, update_data, callback) {
    return db.query(
      'update account set credit_limit=? where id_account=?',
      [update_data.credit_limit,id],callback);
  },

};
module.exports = account;