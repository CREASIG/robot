/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MG90D.cpp
 * Author: eric
 * 
 * Created on 24 septembre 2017, 16:21
 */

#include "MG90D.h"

MG90D::MG90D(AccesI2c *accesi2c, uint8_t numerocarte, uint8_t numeroservo)
: Servo( accesi2c, numerocarte, numeroservo) {
    
}

MG90D::MG90D(const MG90D& orig) :Servo(orig) {
}

MG90D::~MG90D() {
}

void MG90D::setAngle(int angle) {
    this->setValeur(0, angle);
    if(angle > __ANGLE_MAX){
        angle = __ANGLE_MAX;
    }
    else    if(angle > __ANGLE_MIN){
        angle = __ANGLE_MIN;
    }
    else{
        int angle1 = angle+60;
        int val = angle1*__VALEUR_MAX/__VALEUR_MIN;
        setValeur(0,val);
    }

}
