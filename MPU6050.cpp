/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MPU6050.cpp
 * Author: eric
 * 
 * Created on 21 octobre 2017, 19:11
 */

#include "MPU6050.h"
#include "AccesI2c.h"
#include "Gyroscope.h"

MPU6050::MPU6050(AccesI2c *acces, int adressecarte) {
    this->acces = acces;
    this->adressecarte = adressecarte;
    this->acces->selectionComposant(adressecarte);

    acces->ecrireRegistre8bit(MPU6050_RA_GYRO_CONFIG, 0b00000000);
    acces->ecrireRegistre8bit(MPU6050_RA_PWR_MGMT_1, 0b00000010);
    acces->ecrireRegistre8bit(MPU6050_RA_PWR_MGMT_2, 0b00000000);
    acces->ecrireRegistre8bit(MPU6050_RA_INT_ENABLE, 0b00000001);
    acces->ecrireRegistre8bit(MPU6050_RA_ACCEL_CONFIG, 0b00000000);

}

MPU6050::MPU6050(const MPU6050& orig) {
}

MPU6050::~MPU6050() {
}

void MPU6050::lectureAcceleration(int *a) {


    uint8_t block[6];
    this->acces->selectionComposant(adressecarte);
    this->acces->lectureBlock(MPU6050_RA_ACCEL_XOUT_H, sizeof (block), block);

    *a = (int16_t) (block[1] | block[0] << 8);
    *(a + 1) = (int16_t) (block[3] | block[2] << 8);
    *(a + 2) = (int16_t) (block[5] | block[4] << 8);


    if (*a >= 0x8000) {
        *a = -((65535 - *a) + 1);
    }
    if (*(a + 1) >= 0x8000) {
        *(a + 1) = -((65535 - *(a + 1)) + 1);
    }
    if (*(a + 2) >= 0x8000) {
        *(a + 2) = -((65535 - *(a + 2)) + 1);
    }

}

void MPU6050::lectureGyroscope(int *a) {


    uint8_t block[6];
    this->acces->selectionComposant(adressecarte);
    this->acces->lectureBlock(MPU6050_RA_GYRO_XOUT_H, sizeof (block), block);

    *a = (int16_t) (block[1] | block[0] << 8);
    *(a + 1) = (int16_t) (block[3] | block[2] << 8);
    *(a + 2) = (int16_t) (block[5] | block[4] << 8);

    if (*a >= 0x8000) {
        *a = -((65535 - *a) + 1);
    }
    if (*(a + 1) >= 0x8000) {
        *(a + 1) = -((65535 - *(a + 1)) + 1);
    }
    if (*(a + 2) >= 0x8000) {
        *(a + 2) = -((65535 - *(a + 2)) + 1);
    }

}

void MPU6050::calcule() {
    int accRaw[3];
    int gyrRaw[3];
    while (true) {
        lectureAcceleration(accRaw);
        lectureGyroscope(gyrRaw);

        float accel_xout_scaled = accRaw[0] / 16384.0;
        float accel_yout_scaled = accRaw[1] / 16384.0;
        float accel_zout_scaled = accRaw[2] / 16384.0;

        float rotx = get_x_rotation(accRaw[0], accRaw[1], accRaw[2]);
        float roty = get_y_rotation(accRaw[0], accRaw[1], accRaw[2]);
        float rotz = get_z_rotation(accRaw[0], accRaw[1], accRaw[2]);

        this->anglex = rotx;
        this->angley = roty;
        this->anglez = rotz;

        float gyrx = gyrRaw[0] / 131;
        float gyry = gyrRaw[1] / 131;
        float gyrz = gyrRaw[2] / 131;

        this->gyroscopex = gyrx;
        this->gyroscopey = gyry;
        this->gyroscopez = gyrz;

        printf("%d %d %d | %f %f %f |\n", gyrRaw[0], gyrRaw[1], gyrRaw[2], gyrx,gyry,gyrz);
    }
}

int MPU6050::distance(int a, int b) {
    return sqrt((a * a)+(b * b));
}

int MPU6050::get_y_rotation(int x, int y, int z) {
    float radians = atan2(x, distance(y, z));
    return -radians * 180 / M_PI;
}

int MPU6050::get_x_rotation(int x, int y, int z) {
    float radians = atan2(y, distance(x, z));
    return -radians * 180 / M_PI;
}

int MPU6050::get_z_rotation(int x, int y, int z) {
    float radians = atan2(z, distance(x, y));
    return -radians * 180 / M_PI;
}

int MPU6050::getAngleX() {
    return anglex;
}

int MPU6050::getAngleY() {
    return angley;
}

int MPU6050::getAngleZ() {
    return anglez;
}

int MPU6050::getGyroscopeX() {
    return gyroscopex;
}

int MPU6050::getGyroscopeY() {
    return gyroscopey;
}

int MPU6050::getGyroscopeZ() {
    return gyroscopez;
}
