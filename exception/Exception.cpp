/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exception.cpp
 * Author: eric
 * 
 * Created on 19 octobre 2017, 14:10
 */

#include "Exception.h"

Exception::Exception(string const& message ) throw() {
    this->_message = message;
}

Exception::Exception(const Exception& orig) throw() {
}

Exception::~Exception() {
}

const char* Exception::message() const throw ()
 {

    return this->_message.c_str();

}