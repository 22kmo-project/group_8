const db = require('../database');

const user = {
  getById: function(id, callback) {
    return db.query('select * from user where id_user=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from user', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into user (fname,lname,address,phone) values(?,?,?,?)',
      [add_data.fname, add_data.lname, add_data.address, add_data.phone],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from user where id_user=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update user set fname=?,lname=?, address=?, phone=? where id_user=?',
      [update_data.fname, update_data.lname, update_data.address, update_data.phone, id],
      callback
    );
  }
};
module.exports = user;