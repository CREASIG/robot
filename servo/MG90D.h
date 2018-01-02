/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MG90D.h
 * Author: eric
 *
 * Created on 24 septembre 2017, 16:21
 */

#ifndef MG90D_H
#define MG90D_H

#include "Servo.h"

#define __VALEUR_MIN  1740//158
#define __VALEUR_MAX  1930//500

#define __ANGLE_MIN     -60
#define __ANGLE_MAX     60


class MG90D :public Servo{
public:
    MG90D(AccesI2c *accesi2c, uint8_t numerocarte, uint8_t numeroservo);
    MG90D(const MG90D& orig);
    virtual ~MG90D();
    
    // Mettre le servo dans un angle particulier
    virtual void setAngle(int angle);
    
    
private:

};

#endif /* MG90D_H */

