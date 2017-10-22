/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MArche.cpp
 * Author: eric
 * 
 * Created on 19 octobre 2017, 13:47
 */

#include <unistd.h>

#include "Marche.h"
#include "AccesI2c.h"
#include "servo/MG90D.h"
#include "MPU6050.h"

Marche::Marche(Echange * echange) {
    this->echange = echange;
    AccesI2c *accesi2c = new AccesI2c();
    MPU6050 mp(accesi2c,0x68);
    mp.calcule();
    Servo* s = new MG90D(accesi2c, 0x40, 0);
    s->setFrequence(50);
    int angle =0;
    
    while (true) {
        if(angle<-60)
            angle=-60;
        if(angle>60)
            angle=60;
        
        if (echange->getAvancer() > 0) {
            echange->addLog("avancer");
            angle+=echange->getAvancer();
            s->setAngle(angle);
            echange->setAvancer(0);
        }
        if (echange->getReculer() > 0) {
            angle-=echange->getReculer();
            s->setAngle(angle);
            echange->addLog("reculer");
            echange->setReculer(0);
        }
        if (echange->getDroite() > 0) {
            echange->addLog("droite");
            echange->setDroite(0);
        }
        if (echange->getGauche() > 0) {
            echange->addLog("gauche");
            echange->setGauche(0);
        }
        usleep(500);
        
    }
}

Marche::Marche(const Marche & orig) {
}

Marche::~Marche() {
}

