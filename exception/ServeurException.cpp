/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServeurException.cpp
 * Author: eric
 * 
 * Created on 19 octobre 2017, 14:27
 */

#include "ServeurException.h"

ServeurException::ServeurException(string const& message):Exception(message) {
}

ServeurException::ServeurException(const ServeurException& orig):Exception(orig) {
}

ServeurException::~ServeurException() {
}

