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
using namespace std;
#define ADD_ACCELEROMETRE 0x1E
#define ADD_GYROSCOPE 0x19


#define LSM303_CTRL_REG1_A 0x20
#define LSM303_CTRL_REG2_A 0x21
#define LSM303_CTRL_REG3_A 0x22
#define LSM303_CTRL_REG4_A 0x23
#define LSM303_CTRL_REG5_A 0x24
#define LSM303_OUT_X_L_A 0x28
#define LSM303_OUT_X_L_B 0x29
#define LSM303_OUT_Y_L_A 0x2A
#define LSM303_OUT_Y_L_B 0x2B
#define LSM303_OUT_Z_L_A 0x2C
#define LSM303_OUT_Z_L_B 0x2D

Gyroscope::Gyroscope() {

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

    enableIMU();

    gettimeofday(&tvBegin, NULL);


    while (1) {
        startInt = mymillis();


        //read ACC and GYR data
        readACC(accRaw);
        readGYR(gyrRaw);

        //Convert Gyro raw to degrees per second
        rate_gyr_x = (float) gyrRaw[0] * G_GAIN;
        rate_gyr_y = (float) gyrRaw[1] * G_GAIN;
        rate_gyr_z = (float) gyrRaw[2] * G_GAIN;



        //Calculate the angles from the gyro
        gyroXangle += rate_gyr_x*DT;
        gyroYangle += rate_gyr_y*DT;
        gyroZangle += rate_gyr_z*DT;




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


        printf("   GyroX  %7.3f \t AccXangle \e[m %7.3f \t \033[22;31mCFangleX %7.3f\033[0m\t GyroY  %7.3f \t AccYangle %7.3f \t \033[22;36mCFangleY %7.3f\t\033[0m\n", gyroXangle, AccXangle, CFangleX, gyroYangle, AccYangle, CFangleY);

        //Each loop should be at least 20ms.
        while (mymillis() - startInt < (DT * 1000)) {
            usleep(100);
        }

        printf("Loop Time %d\t", mymillis() - startInt);
    }

    /*    
    int file_i2c;
    int length;
    unsigned char buffer[60] = {0};

    std::cout << "ouverture du fichier" << endl;
    //----- OPEN THE I2C BUS -----
    char *filename = (char*) "/dev/i2c-1";
    if ((file_i2c = open(filename, O_RDWR)) < 0) {
        //ERROR HANDLING: you can check errno to see what went wrong
        printf("Failed to open the i2c bus");
        return;
    }

    std::cout << "ouverture de la carte" << endl;
    if (ioctl(file_i2c, I2C_SLAVE, ADD_ACCELEROMETRE) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        //ERROR HANDLING; you can check errno to see what went wrong
        return;
    }

    //initialisation de l'accelerometre
    i2c_smbus_write_byte_data(file_i2c, LSM303_CTRL_REG1_A, 0b01100111);
    i2c_smbus_write_byte_data(file_i2c, LSM303_CTRL_REG2_A, 0b00100000);


    int v = 0;
    while (true) {
//        usleep(50000);
        
        int8_t x1 = i2c_smbus_read_byte_data(file_i2c, 0x80 |LSM303_OUT_X_L_A);
        int8_t x2 = i2c_smbus_read_byte_data(file_i2c, 0x80 |LSM303_OUT_X_L_B);
        int16_t x = (x1 | (x2  << 8)) ;

        uint8_t y1 = i2c_smbus_read_byte_data(file_i2c, LSM303_OUT_Y_L_A);
        uint8_t y2 = i2c_smbus_read_byte_data(file_i2c, LSM303_OUT_Y_L_B);
        int16_t y = (y1 | (y2  << 8)) >>4;

        uint8_t z1 = i2c_smbus_read_byte_data(file_i2c, LSM303_OUT_Z_L_A);
        uint8_t z2 = i2c_smbus_read_byte_data(file_i2c, LSM303_OUT_Z_L_B);
        int16_t z = (z1 | (z2  << 8)) >>4;

//        if (-65 > v - x && v - x < 65)
//        if (-40 > v - x && v - x < 40)
//        if(x>200)
        {
            printf("%d|%d|%d\n",x,y,z);
        }
        v = x;
    }
     */
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


void  Gyroscope::readBlock(uint8_t command, uint8_t size, uint8_t *data)
{
    int result = i2c_smbus_read_i2c_block_data(file, command, size, data);
    if (result != size)
    {
        printf("Failed to read block from I2C.");
        exit(1);
    }
}

void Gyroscope::selectDevice(int file, int addr)
{
        if (ioctl(file, I2C_SLAVE, addr) < 0) {
		 printf("Failed to select I2C device.");
        }
}


void Gyroscope::readACC(int  *a)
{
        uint8_t block[6];
        selectDevice(file,ACC_ADDRESS);
        readBlock(0x80 | OUT_X_L_A, sizeof(block), block);

        *a = (int16_t)(block[0] | block[1] << 8);
        *(a+1) = (int16_t)(block[2] | block[3] << 8);
        *(a+2) = (int16_t)(block[4] | block[5] << 8);

}


void Gyroscope::readMAG(int  *m)
{
        uint8_t block[6];
        selectDevice(file,MAG_ADDRESS);
        readBlock(0x80 | OUT_X_L_M, sizeof(block), block);

        *m = (int16_t)(block[0] | block[1] << 8);
        *(m+1) = (int16_t)(block[2] | block[3] << 8);
        *(m+2) = (int16_t)(block[4] | block[5] << 8);

}

void Gyroscope::readGYR(int *g)
{
	uint8_t block[6];
        selectDevice(file,GYR_ADDRESS);
	readBlock(0x80 | OUT_X_L_G, sizeof(block), block);

        *g = (int16_t)(block[0] | block[1] << 8);
        *(g+1) = (int16_t)(block[2] | block[3] << 8);
        *(g+2) = (int16_t)(block[4] | block[5] << 8);
}


void Gyroscope::writeAccReg(uint8_t reg, uint8_t value)
{
    selectDevice(file,ACC_ADDRESS);
  int result = i2c_smbus_write_byte_data(file, reg, value);
    if (result == -1)
    {
        printf ("Failed to write byte to I2C Acc.");
        exit(1);
    }
}

void Gyroscope::writeMagReg(uint8_t reg, uint8_t value)
{
    selectDevice(file,MAG_ADDRESS);
  int result = i2c_smbus_write_byte_data(file, reg, value);
    if (result == -1)
    {
        printf("Failed to write byte to I2C Mag.");
        exit(1);
    }
}


void Gyroscope::writeGyrReg(uint8_t reg, uint8_t value)
{
    selectDevice(file,GYR_ADDRESS);
  int result = i2c_smbus_write_byte_data(file, reg, value);
    if (result == -1)
    {
        printf("Failed to write byte to I2C Gyr.");
        exit(1);
    }
}


void Gyroscope::enableIMU()
{

	__u16 block[I2C_SMBUS_BLOCK_MAX];

        int res, bus,  size;


        char filename[20];
        sprintf(filename, "/dev/i2c-%d", 1);
        file = open(filename, O_RDWR);
        if (file<0) {
		printf("Unable to open I2C bus!");
                exit(1);
        }

        // Enable accelerometer.
        writeAccReg(CTRL_REG1_XM, 0b01100111); //  z,y,x axis enabled, continuous update,  100Hz data rate
        writeAccReg(CTRL_REG2_XM, 0b00100000); // +/- 16G full scale

        //Enable the magnetometer
        writeMagReg( CTRL_REG5_XM, 0b11110000); // Temp enable, M data rate = 50Hz
        writeMagReg( CTRL_REG6_XM, 0b01100000); // +/-12gauss
        writeMagReg( CTRL_REG7_XM, 0b00000000); // Continuous-conversion mode

	 // Enable Gyro
        writeGyrReg(CTRL_REG1_G, 0b00001111); // Normal power mode, all axes enabled
        writeGyrReg(CTRL_REG4_G, 0b00110000); // Continuos update, 2000 dps full scale

}
