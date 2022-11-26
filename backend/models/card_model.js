const db = require('../database');
const bcrypt = require("bcryptjs");

const saltRounds = 10;


const card = {
  checkPin: function(card_number, callback) {
    return db.query('SELECT pin FROM card WHERE card_number = ?',[card_number], callback); 
  },

  getById: function(id, callback) {
    return db.query('select * from card where id_card=?', [id], callback);
  },

  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  
  add: function(add_data, callback) {
    bcrypt.hash(add_data.pin, saltRounds, function (err, hashedPin){
    return db.query(
      'insert into card (card_number,pin,id_account,id_user) values(?,?,?,?)',
      [add_data.card_number, hashedPin, add_data.id_account, add_data.id_user],
      callback);
    });
  },

  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },

  update: function(id, update_data, callback) {
    bcrypt.hash(update_data.pin, saltRounds, function (err, hashedPin) {
            return db.query(
                'update card set card_number=?,pin=?, id_account=?,id_user=? where id_card=?',
                [update_data.card_number, hashedPin, update_data.id_account, 
                update_data.id_user, id],callback);
            });
        }      
      };
module.exports = card;