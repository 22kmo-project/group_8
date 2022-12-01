const db = require('../database');

const idcard = {
  getCardId: function(card_number, callback) {
    return db.query('select id_card from card where card_number=?', [card_number], callback);
  }
};

module.exports = idcard;