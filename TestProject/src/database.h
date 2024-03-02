#ifndef DATABASE_H
#define DATABASE_H
#include <postgresql/libpq-fe.h>
#include <iostream>
#include <string>

class Database
{
public:
    Database();
    void insertCountry(const std::string &country);
private:
    PGconn * connection;
};

#endif // DATABASE_H
