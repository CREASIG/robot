/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gyroscope.h
 * Author: eric
 *
 * Created on 10 septembre 2017, 15:09
 */

#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include <unistd.h>    //Needed for I2C port
#include <fcntl.h>    //Needed for I2C port
#include <sys/ioctl.h>   //Needed for I2C port
#include <linux/i2c-dev.h>  //Needed for I2C port
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "AccesI2c.h"


#define MAG_ADDRESS            0x19
#define ACC_ADDRESS            0x1E
//#define GYR_ADDRESS            0x1E



/** LSM9DS0 Gyro Registers **/
/*
#define WHO_AM_I_G			0x0F
#define CTRL_REG1_G			0x20
#define CTRL_REG2_G			0x21
#define CTRL_REG3_G			0x22
#define CTRL_REG4_G			0x23
#define CTRL_REG5_G			0x24
#define REFERENCE_G			0x25
#define STATUS_REG_G			0x27
#define OUT_X_L_G			0x28
#define OUT_X_H_G			0x29
#define OUT_Y_L_G			0x2A
#define OUT_Y_H_G			0x2B
#define OUT_Z_L_G			0x2C
#define OUT_Z_H_G			0x2D
#define FIFO_CTRL_REG_G			0x2E
#define FIFO_SRC_REG_G			0x2F
#define INT1_CFG_G			0x30
#define INT1_SRC_G			0x31
#define INT1_THS_XH_G			0x32
#define INT1_THS_XL_G			0x33
#define INT1_THS_YH_G			0x34
#define INT1_THS_YL_G			0x35
#define INT1_THS_ZH_G			0x36
#define INT1_THS_ZL_G			0x37
#define INT1_DURATION_G			0x38
 */


#define CTRL_REG1_A 0x20
#define CTRL_REG2_A 0x21
#define CTRL_REG3_A 0x22
#define CTRL_REG4_A 0x23
#define CTRL_REG5_A 0x24
#define CTRL_REG6_A 0x25
#define REFERENCE_A 0x26
#define STATUS_REG_A 0x27
#define OUT_X_L_A 0x28
#define OUT_X_H_A 0x29
#define OUT_Y_L_A 0x2A
#define OUT_Y_H_A 0x2B
#define OUT_Z_L_A 0x2C
#define OUT_Z_H_A 0x2D
#define FIFO_CTRL_REG_A 0x2E
#define FIFO_SRC_REG_A 0x2F  
#define INT1_CFG_A 0x30 
#define INT1_SOURCE_A 0x31
#define INT1_THS_A 0x32
#define INT1_DURATION_A 0x33
#define INT2_CFG_A 0x34
#define INT2_SOURCE_A 0x35
#define INT2_THS_A 0x36
#define INT2_DURATION_A 0x37
#define CLICK_CFG_A 0x38
#define CLICK_SRC_A 0x39 
#define CLICK_THS_A 0x3A 
#define TIME_LIMIT_A 0x3B
#define TIME_LATENCY_A 0x3C 
#define TIME_WINDOW_A 0x3D 
#define CRA_REG_M   0x0
#define CRB_REG_M   0x1
#define MR_REG_M 0x02
#define OUT_X_H_M 0x03 
#define OUT_X_L_M 0x04 
#define OUT_Z_H_M  0x05
#define OUT_Z_L_M  0x06 
#define OUT_Y_H_M  0x07 
#define OUT_Y_L_M  0x08 
#define SR_REG_Mg  0x09 
#define IRA_REG_M  0x0A 
#define IRB_REG_M  0x0B 
#define IRC_REG_M  0x0C 
#define TEMP_OUT_H_M 0x31
#define TEMP_OUT_L_M 0x32



#define DT 0.02         // [s/loop] loop period. 20ms
#define AA 0.97         // complementary filter constant

#define A_GAIN 0.0573      // [deg/LSB]
#define G_GAIN 0.070     // [deg/s/LSB]
#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846

class Gyroscope {
public:
    Gyroscope(AccesI2c *acces, int adressecarte);
    Gyroscope(const Gyroscope& orig);
    virtual ~Gyroscope();
    
    void calcule();
    int getAngleX();
    int getAngleY();
    int getAngleZ();
private:
    void INThandler(int sig);
    int mymillis();
    int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1);

    void lectureAcceleration(int *a);

    void lectureMagnetisme(int *m);
    void lectureGyroscope(int *g);
    void enableIMU();

    int anglex;
    int angley;
    int anglez;
    
    AccesI2c *acces;
    int adressecarte;
};

#endif /* GYROSCOPE_H */

