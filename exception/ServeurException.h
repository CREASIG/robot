/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServeurException.h
 * Author: eric
 *
 * Created on 19 octobre 2017, 14:27
 */

#ifndef SERVEUREXCEPTION_H
#define SERVEUREXCEPTION_H

#include "Exception.h"


class ServeurException :public Exception{
public:

    ServeurException(string const& message="");
    ServeurException(const ServeurException& orig);
    virtual ~ServeurException();
private:

};

#endif /* SERVEUREXCEPTION_H */

