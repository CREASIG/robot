/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Information.cpp
 * Author: eric
 * 
 * Created on 11 octobre 2017, 14:18
 */

#include "Information.h"

Information::Information(Echange *echange) {
    this->echange = echange;
}

Information::Information(const Information& orig) {
}

Information::~Information() {
}

void Information::setInformation(string information) {

}

string Information::getInformation(string type) {
    return type;
}

