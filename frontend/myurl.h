#ifndef MYURL_H
#define MYURL_H

#include <QString>

class MyURL
{
public:
    MyURL();
    static QString getBaseURL();


private:
    static QString base_url;
};

#endif // MYURL_H
