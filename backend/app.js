var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');

function authenticateToken(req, res, next)  {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]

    console.log("token = "+token);
    if (token==null) return res.sendStatus(401)

    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
        console.log(err)

        if (err) return res.sendStatus(403)

        req.user = user
        
        next()
    })
}

var indexRouter = require('./routes/index');
var userRouter = require('./routes/user');
var accountRouter = require('./routes/account');
var loginRouter = require('./routes/login');
var cardRouter = require('./routes/card');
var transactionRouter = require('./routes/transaction');
var idcardRouter = require('./routes/idcard'); 
var idaccountRouter = require ('./routes/idaccount');
var getFiveTransactionsRouter = require('./routes/getFiveTransactions');





var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));




app.use('/login', loginRouter); //login not protected
app.use(authenticateToken);

//protected
app.use('/', indexRouter);
app.use('/user', userRouter);
app.use('/card',cardRouter);
app.use('/account', accountRouter);
app.use('/transaction', transactionRouter);
app.use('/idcard',idcardRouter);
app.use('/idaccount',idaccountRouter);
app.use('/getFiveTransactions', getFiveTransactionsRouter);






module.exports = app;
