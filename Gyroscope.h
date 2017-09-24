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

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAG_ADDRESS            0x19
#define ACC_ADDRESS            0x19
#define GYR_ADDRESS            0x1E



/** LSM9DS0 Gyro Registers **/
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

//////////////////////////////////////////
// LSM9DS0 Accel/Magneto (XM) Registers //
//////////////////////////////////////////
#define OUT_TEMP_L_XM			0x05
#define OUT_TEMP_H_XM			0x06
#define STATUS_REG_M			0x07
#define OUT_X_L_M			0x08
#define OUT_X_H_M			0x09
#define OUT_Y_L_M			0x0A
#define OUT_Y_H_M			0x0B
#define OUT_Z_L_M			0x0C
#define OUT_Z_H_M			0x0D
#define WHO_AM_I_XM			0x0F
#define INT_CTRL_REG_M			0x12
#define INT_SRC_REG_M			0x13
#define INT_THS_L_M			0x14
#define INT_THS_H_M			0x15
#define OFFSET_X_L_M			0x16
#define OFFSET_X_H_M			0x17
#define OFFSET_Y_L_M			0x18
#define OFFSET_Y_H_M			0x19
#define OFFSET_Z_L_M			0x1A
#define OFFSET_Z_H_M			0x1B
#define REFERENCE_X			0x1C
#define REFERENCE_Y			0x1D
#define REFERENCE_Z			0x1E
#define CTRL_REG0_XM			0x1F
#define CTRL_REG1_XM			0x20
#define CTRL_REG2_XM			0x21
#define CTRL_REG3_XM			0x22
#define CTRL_REG4_XM			0x23
#define CTRL_REG5_XM			0x24
#define CTRL_REG6_XM			0x25
#define CTRL_REG7_XM			0x26
#define STATUS_REG_A			0x27
#define OUT_X_L_A			0x28
#define OUT_X_H_A			0x29
#define OUT_Y_L_A			0x2A
#define OUT_Y_H_A			0x2B
#define OUT_Z_L_A			0x2C
#define OUT_Z_H_A			0x2D
#define FIFO_CTRL_REG			0x2E
#define FIFO_SRC_REG			0x2F
#define INT_GEN_1_REG			0x30
#define INT_GEN_1_SRC			0x31
#define INT_GEN_1_THS			0x32
#define INT_GEN_1_DURATION		0x33
#define INT_GEN_2_REG			0x34
#define INT_GEN_2_SRC			0x35
#define INT_GEN_2_THS			0x36
#define INT_GEN_2_DURATION		0x37
#define CLICK_CFG			0x38
#define CLICK_SRC			0x39
#define CLICK_THS			0x3A
#define TIME_LIMIT			0x3B
#define TIME_LATENCY			0x3C
#define TIME_WINDOW	0x3D


#define DT 0.02         // [s/loop] loop period. 20ms
#define AA 0.97         // complementary filter constant

#define A_GAIN 0.0573      // [deg/LSB]
#define G_GAIN 0.070     // [deg/s/LSB]
#define RAD_TO_DEG 57.29578
#define M_PI 3.14159265358979323846

class Gyroscope {
public:
    Gyroscope();
    Gyroscope(const Gyroscope& orig);
    virtual ~Gyroscope();
private:
void INThandler(int sig) ;
int mymillis();
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1);

void  readBlock(uint8_t command, uint8_t size, uint8_t *data);
void selectDevice(int file, int addr);

void readACC(int  *a);

void readMAG(int  *m);
void readGYR(int *g);
void writeAccReg(uint8_t reg, uint8_t value);
void writeMagReg(uint8_t reg, uint8_t value);
void writeGyrReg(uint8_t reg, uint8_t value);
void enableIMU();

int file;

};

#endif /* GYROSCOPE_H */

