#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<iostream>

using namespace std;

class MyException: public exception {
public:
    MyException(string msg): msg(msg) {}
    virtual char const * what() const throw() {return msg.c_str();}
private:
    string msg;
};

#endif // MYEXCEPTION_H
