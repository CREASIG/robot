/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MArche.h
 * Author: eric
 *
 * Created on 19 octobre 2017, 13:47
 */

#ifndef MARCHE_H
#define MARCHE_H

#include "Echange.h"


class Marche {
public:
    Marche( Echange * echange);
    Marche(const Marche& orig);
    virtual ~Marche();
private:
    Echange * echange;
};

#endif /* MARCHE_H */

