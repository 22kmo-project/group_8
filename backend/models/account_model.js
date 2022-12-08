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
      'insert into account (account_type,balance,credit_limit,account_owner) values(?,?,?,?)',
      [add_data.account_type, add_data.balance, add_data.credit_limit, add_data.account_owner], callback);
  },
  delete: function (id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      'update account set account_type=?,balance=?, credit_limit=?,account_owner=? where id_account=?',
      [update_data.account_type, update_data.balance, update_data.credit_limit, update_data.account_owner, id], callback);
  },

  balance: function (id, update_data, callback) {
    return db.query(
      'update account set balance=? where id_account=?',
      [update_data.balance, id], callback);
  },

  creditlimit: function (id, update_data, callback) {
    return db.query(
      'update account set credit_limit=? where id_account=?',
      [update_data.credit_limit, id], callback);
  },

};
module.exports = account;