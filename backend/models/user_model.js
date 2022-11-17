const db = require('../database');

const user = {
  getById: function(id_card, callback) {
    return db.query('select * from card where id_card=?', [id_card], callback);
  },

  getAll: function(callback) {
    return db.query('select * from card', callback);
  },

  add: function(add_data, callback) {
    return db.query(
      'insert into user (card_number,pin,id_account,id_user) values(?,?,?,?)',
      [add_data.card_number, add_data.pin, add_data.id_account, add_data.id_user],
      callback
    );
  },

  delete: function(id_, callback) {
    return db.query('delete from card where id_card=?', [id_card], callback);
  },
  update: function(id_card, update_data, callback) {
    return db.query(
      'update user set card_number=?,pin=?, id_account=?, id_user=? where id_card=?',
      [update_data.card_number, update_data.pin, update_id_account, update_data.id_user, id_card],
      callback
    );
  }
};
module.exports = user;