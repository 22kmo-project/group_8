
#include "myurl.h"

MyURL::MyURL()
{

}

QString MyURL::getBaseURL()
{
    return base_url;
}

QString MyURL::base_url{
    "http://localhost:3000"

};
