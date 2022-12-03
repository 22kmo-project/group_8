const db = require('../database');

const account = {
  getById: function (id, callback) {
    return db.query('select * from account where id_account=?', [id], callback);
  },

  //tämä koodi on uudempi versio kommentoidusta... katsotaan toimiiko

  /*owner: function (id,callback) {
    return db.query('select concat(u.fname, " ", u.lname) as "account_owner" from user as u join account as a using(id_user) where id_account=?', [id], callback);
  },

  //owner: function (id,callback) {
   // return db.query('select concat(u.fname, " ", u.lname) as owner from user as u join account as a using(id_user) where id_account=?', [id], callback);
  //},

  /*owner: function (id,callback) {
    return db.query('select account_owner from account where id_account=?', [id], callback);
  },*/

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
      'insert into account (account_type,balance,id_card, id_user, account_owner) values(?,?,?,?,?)',
      [add_data.account_type, add_data.balance, add_data.id_card, add_data.id_user, add_data.account_owner], callback);
  },
  delete: function (id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      'update account set account_type=?,balance=?, id_card=?, id_user=?,account_owner=? where id_account=?',
      [update_data.account_type, update_data.balance, update_data.id_card, update_data.id_user, update_data.account_owner, id],callback);
  },


};
module.exports = account;