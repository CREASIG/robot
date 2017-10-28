/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MPU6050.h
 * Author: eric
 *
 * Created on 21 octobre 2017, 19:11
 */

#ifndef MPU6050_H
#define MPU6050_H

#include <cmath>

#include "MPU6050_Register.h"
#include "AccesI2c.h"
#include "GPIOClass.h"


#define M_PIl          3.141592653589793238462643383279502884L /* pi */

class MPU6050 {
public:
    MPU6050(AccesI2c* acces, int adressecarte,int numero);
    MPU6050(const MPU6050& orig);
    virtual ~MPU6050();

    void calcule();

    int getAngleX();
    int getAngleY();
    int getAngleZ();

    int getGyroscopeX();
    int getGyroscopeY();
    int getGyroscopeZ();
    
private:

    void lectureGyroscope(int *a);
    void lectureAcceleration(int *a);

    int distance(int a, int b);

    int get_y_rotation(int x, int y, int z);
    int get_z_rotation(int x, int y, int z);
    int get_x_rotation(int x, int y, int z);

    AccesI2c *acces;
    int adressecarte;
    
    int anglex;
    int angley;
    int anglez;
    int gyroscopex;
    int gyroscopey;
    int gyroscopez;
    int numero;
    
    GPIOClass *gpio;
    
};

#endif /* MPU6050_H */

