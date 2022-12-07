const db = require('../database');

const transaction = {
  getById: function (id, callback) {
    return db.query('SELECT id_transaction, date_format(transaction_date, "%d.%m.%Y") as "transaction_date", activity, amount FROM transaction INNER JOIN account ON transaction.id_account=account.id_account WHERE account.id_account=? ORDER BY id_transaction DESC LIMIT 10', [id], callback);
  },
  getAll: function (callback) {
    return db.query('select * from transaction', callback);
  },
  getTransactions: function (id, callback) {
    return db.query('select from transaction where id_account=?', [id], callback);
  },
  add: function (add_data, callback) {
    return db.query(
      'insert into transaction (transaction_date,activity,amount,id_account) values(?,?,?,?)',
      [add_data.transaction_date, add_data.activity, add_data.amount, add_data.id_account],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query('delete from transaction where id_transaction=?', [id], callback);
  },
  update: function (id, update_data, callback) {
    return db.query(
      'update transaction set transaction_date=?,activity=?,amount=? where id_transaction=?',
      [update_data.transaction_date, update_data.activity, update_data.amount, id],
      callback
    );
  },
  getFiveTransactions:function (id, callback) {
    return db.query('SELECT id_transaction, date_format(transaction_date, "%d.%m.%Y") as "transaction_date", activity, amount FROM transaction INNER JOIN account ON transaction.id_account=account.id_account WHERE account.id_account=? ORDER BY id_transaction DESC LIMIT 5', [id], callback);

  }
  };
module.exports = transaction;