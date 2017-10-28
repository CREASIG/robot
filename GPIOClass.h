/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GPIOClass.h
 * Author: eric
 *
 * Created on 8 septembre 2017, 19:26
 */

#ifndef GPIOCLASS_H
#define GPIOCLASS_H

#include <string>
#include "wiringPi.h"


using namespace std;

class GPIOClass {
public:
    GPIOClass(int gpionum); // create a GPIO object that controls GPIOx, where x is passed to this constructor
    void setval_gpio(int val); // Set GPIO Value (putput pins)
    int getval_gpio(); // Get GPIO Value (input/ output pins)
    int get_gpionum(); // return the GPIO number associated with the instance of an object
private:
    int gpionum; // GPIO number associated with the instance of an object

};

#endif /* GPIOCLASS_H */

