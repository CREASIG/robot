/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exception.h
 * Author: eric
 *
 * Created on 19 octobre 2017, 14:10
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class Exception : public exception{
public:
    Exception(string const& message) throw() ;
    Exception(const Exception& orig) throw();
    virtual ~Exception() throw();
    virtual const char* message() const throw ();

private:
    string _message;
};

#endif /* EXCEPTION_H */

