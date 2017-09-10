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

class Gyroscope {
public:
    Gyroscope();
    Gyroscope(const Gyroscope& orig);
    virtual ~Gyroscope();
private:

};

#endif /* GYROSCOPE_H */

