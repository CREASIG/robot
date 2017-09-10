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

#include "Gyroscope.h"
using namespace std;

Gyroscope::Gyroscope() {
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
    int addr = 0x1d; //<<<<<The I2C address of the slave
    if (ioctl(file_i2c, I2C_SLAVE, addr) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        //ERROR HANDLING; you can check errno to see what went wrong
        return;
    }

    i2c_smbus_write_byte_data(file_i2c, 0x2D, 0);
    i2c_smbus_write_byte_data(file_i2c, 0x2D, 16);
    i2c_smbus_write_byte_data(file_i2c, 0x2D, 8);


    while (true) {
        int x1 = i2c_smbus_read_byte_data(file_i2c, 0x32);
        int x2 = i2c_smbus_read_byte_data(file_i2c, 0x33);
        int x = x1+(x2<<8);
        
        int y1 = i2c_smbus_read_byte_data(file_i2c, 0x34);
        int y2 = i2c_smbus_read_byte_data(file_i2c, 0x35);
        int y = y1+(y2<<8);
        
        int z1 = i2c_smbus_read_byte_data(file_i2c, 0x36);
        int z2 = i2c_smbus_read_byte_data(file_i2c, 0x37);
        int z = z1+(z2<<8);

        printf("%x|%x|%x\n",x,x1,x2);
        //printf("Data read: %x-%x %x-%x %x\n", x, i2c_smbus_read_byte_data(file_i2c, 0x34), i2c_smbus_read_byte_data(file_i2c, 0x35), i2c_smbus_read_byte_data(file_i2c, 0x36), i2c_smbus_read_byte_data(file_i2c, 0x37));
    }


    /*
    std::cout << "lecture" << endl;
    //ioctl(file_i2c, I2C_SLAVE, 0x33);
    //----- READ BYTES -----
    length = 4; //<<< Number of bytes to read
    if (read(file_i2c, buffer, length) != length) //read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
    {
        //ERROR HANDLING: i2c transaction failed
        printf("Failed to read from the i2c bus.\n");
    } else {
        printf("Data read: %#08x\n", buffer);
    }

    

    //----- WRITE BYTES -----
    buffer[0] = 0x03;
    buffer[1] = 0x03;
    length = 2; //<<< Number of bytes to write
    if (write(file_i2c, buffer, length) != length) //write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
    {
        printf("Failed to write to the i2c bus.\n");
    }

    length = 57; //<<< Number of bytes to read
    if (read(file_i2c, buffer, length) != length) //read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
    {
        //ERROR HANDLING: i2c transaction failed
        printf("Failed to read from the i2c bus.\n");
    } else {
        printf("1Data read: %#08x\n", buffer);
    }
     * */
}

Gyroscope::Gyroscope(const Gyroscope& orig) {
}

Gyroscope::~Gyroscope() {
}

