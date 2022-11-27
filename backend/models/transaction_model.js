const db = require('../database');

const transaction = {
  getById: function(id, callback) {
    return db.query('select * from transaction where id_transaction=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from transaction', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into transaction (id_transaction,transaction_date,activity,amount,id_account,id_user) values(?,?,?,?,?,?)',
      [add_data.id_transaction, add_data.transaction_date, add_data.activity, add_data.amount, add_data.id_account,add_data.id_user],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transaction where id_transaction=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update transaction set transaction_date=?,activity=?,amount=? where id_transaction=?',
      [update_data.transaction_date, update_data.activity,update_data.amount, id],
      callback
    );
  }
};
module.exports = transaction;