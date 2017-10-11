/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Information.h
 * Author: eric
 *
 * Created on 11 octobre 2017, 14:18
 */

#ifndef INFORMATION_H
#define INFORMATION_H

#include "Echange.h"


class Information {
public:
    Information(Echange *echange);
    Information(const Information& orig);
    virtual ~Information();
    void setInformation(string information);
    string getInformation(string type);
private:
    Echange *echange;
};

#endif /* INFORMATION_H */

