/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AfficheurSimple.h
 * Author: eric
 *
 * Created on 9 septembre 2017, 13:13
 */

#ifndef AFFICHEURSIMPLE_H
#define AFFICHEURSIMPLE_H

#include "GPIOClass.h"

class AfficheurSimple {
public:
    AfficheurSimple();
    AfficheurSimple(const AfficheurSimple& orig);
    void afficher(int nombre);
    virtual ~AfficheurSimple();
private:
GPIOClass* srlclk;
GPIOClass* ser;
GPIOClass* rclk;
GPIOClass* srlclr;
};

#endif /* AFFICHEURSIMPLE_H */

