/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gyroscope.cpp
 * Author: eric
 * 
 * Created on 10 septembre 2017, 15:09
 */

#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <sys/time.h>


#include "Gyroscope.h"
#include "AccesI2c.h"
using namespace std;
#define ADD_ACCELEROMETRE 0x19
#define ADD_GYROSCOPE 0x19

Gyroscope::Gyroscope(AccesI2c *acces, int adressecarte) {

    this->acces = acces;
    this->adressecarte = adressecarte;
    enableIMU();
}

void Gyroscope::calcule() {
    float rate_gyr_y = 0.0; // [deg/s]
    float rate_gyr_x = 0.0; // [deg/s]
    float rate_gyr_z = 0.0; // [deg/s]

    int accRaw[3];
    int magRaw[3];
    int gyrRaw[3];



    float gyroXangle = 0.0;
    float gyroYangle = 0.0;
    float gyroZangle = 0.0;
    float AccYangle = 0.0;
    float AccXangle = 0.0;
    float CFangleX = 0.0;
    float CFangleY = 0.0;

    int startInt = mymillis();
    struct timeval tvBegin, tvEnd, tvDiff;


    //    signal(SIGINT, INThandler);


    gettimeofday(&tvBegin, NULL);


    startInt = mymillis();


    //read ACC and GYR data
    lectureAcceleration(accRaw);
    //lectureGyroscope(gyrRaw);


    //Convert Gyro raw to degrees per second
    //rate_gyr_x = (float) gyrRaw[0] * G_GAIN;
    //rate_gyr_y = (float) gyrRaw[1] * G_GAIN;
    //rate_gyr_z = (float) gyrRaw[2] * G_GAIN;



    //Calculate the angles from the gyro
    //gyroXangle += rate_gyr_x*DT;
    //gyroYangle += rate_gyr_y*DT;
    //gyroZangle += rate_gyr_z*DT;


    //        printf("%u %u %u \n", accRaw[0] , accRaw[1], accRaw[2]);

    //Convert Accelerometer values to degrees
    AccXangle = (float) (atan2(accRaw[1], accRaw[2]) + M_PI) * RAD_TO_DEG;
    AccYangle = (float) (atan2(accRaw[2], accRaw[0]) + M_PI) * RAD_TO_DEG;

    //Change the rotation value of the accelerometer to -/+ 180 and move the Y axis '0' point to up.
    //Two different pieces of code are used depending on how your IMU is mounted.
    //If IMU is upside down
    /*        
            if (AccXangle >180)
                    AccXangle -= (float)360.0;
            AccYangle-=90;
            if (AccYangle >180)
                    AccYangle -= (float)360.0;
     */
    //If IMU is up the correct way, use these lines

    AccXangle -= (float) 180.0;
    if (AccYangle > 90)
        AccYangle -= (float) 270;
    else
        AccYangle += (float) 90;


    //Complementary filter used to combine the accelerometer and gyro values.
    CFangleX = AA * (CFangleX + rate_gyr_x * DT) +(1 - AA) * AccXangle;
    CFangleY = AA * (CFangleY + rate_gyr_y * DT) +(1 - AA) * AccYangle;

    anglex = AccXangle;
    angley = AccYangle;
    //anglez = Acc
    printf("   AccXang=%7.3f CFangX=%7.3f \t AccYang=%7.3f CFangY=%7.3f \n", AccXangle, CFangleX, AccYangle, CFangleY);

    //Each loop should be at least 20ms.
//    while (mymillis() - startInt < (DT * 20000)) {
        usleep(10000);
//    }

    printf(" %d ", mymillis() - startInt);

}

int Gyroscope::getAngleX() {
    return anglex;
}

int Gyroscope::getAngleY() {
    return angley;
}

int Gyroscope::getAngleZ() {
    return anglez;
}

Gyroscope::Gyroscope(const Gyroscope& orig) {
}

Gyroscope::~Gyroscope() {
}

void Gyroscope::INThandler(int sig) {
    signal(sig, SIG_IGN);
    exit(0);
}

int Gyroscope::mymillis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
}

int Gyroscope::timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1) {
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;
    return (diff < 0);
}

void Gyroscope::lectureAcceleration(int *a) {
    uint8_t block[6];
    this->acces->selectionComposant(adressecarte);
    this->acces->lectureBlock(0x80 | OUT_X_L_A, sizeof (block), block);

    *a = (int16_t) (block[0] | block[1] << 8);
    *(a + 1) = (int16_t) (block[2] | block[3] << 8);
    *(a + 2) = (int16_t) (block[4] | block[5] << 8);

}

void Gyroscope::lectureMagnetisme(int *m) {
    uint8_t block[6];
    this->acces->selectionComposant(adressecarte);
    this->acces->lectureBlock(OUT_X_L_M, sizeof (block), block);

    *m = (int16_t) (block[0] | block[1] << 8);
    *(m + 1) = (int16_t) (block[2] | block[3] << 8);
    *(m + 2) = (int16_t) (block[4] | block[5] << 8);

}

void Gyroscope::lectureGyroscope(int *g) {
    uint8_t block[6];
    //        selectDevice(file,GYR_ADDRESS);
    //	readBlock(0x80 | OUT_X_L_G, sizeof(block), block);

    *g = (int16_t) (block[0] | block[1] << 8);
    *(g + 1) = (int16_t) (block[2] | block[3] << 8);
    *(g + 2) = (int16_t) (block[4] | block[5] << 8);
}

void Gyroscope::enableIMU() {

    acces->selectionComposant(adressecarte);
    // Enable accelerometer.
    acces->ecrireRegistre8bit(CTRL_REG1_A, 0b01010111); //  z,y,x axis enabled, continuous update,  100Hz data rate
    acces->ecrireRegistre8bit(CTRL_REG2_A, 0b00000000);
    acces->ecrireRegistre8bit(CTRL_REG3_A, 0b00000000);
    acces->ecrireRegistre8bit(CTRL_REG4_A, 0b00000000);
    acces->ecrireRegistre8bit(CTRL_REG5_A, 0b01100100);
    acces->ecrireRegistre8bit(CTRL_REG6_A, 0b00100000);

    //Enable the magnetometer
    //        acces->ecrireRegistre8bit( CTRL_REG5_A, 0b00000011); // Temp enable, M data rate = 50Hz
    //        acces->ecrireRegistre8bit( CTRL_REG6_XM, 0b01100000); // +/-12gauss
    //        acces->ecrireRegistre8bit( CTRL_REG7_XM, 0b00000000); // Continuous-conversion mode

    // Enable Gyro
    //        acces->ecrireRegistre8bit(CTRL_REG1_G, 0b00001111); // Normal power mode, all axes enabled
    //        acces->ecrireRegistre8bit(CTRL_REG4_G, 0b00110000); // Continuos update, 2000 dps full scale

}
