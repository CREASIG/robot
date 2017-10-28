/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GPIOClass.cpp
 * Author: eric
 * 
 * Created on 8 septembre 2017, 19:26
 */

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include "GPIOClass.h"

using namespace std;

GPIOClass::GPIOClass(int gnum) {
    if (wiringPiSetup() == -1)
        exit(1);

    pinMode(gnum, OUTPUT);
    digitalWrite(gpionum, 0);

    this->gpionum = gnum; //Instatiate GPIOClass object for GPIO pin number "gnum"
}


void GPIOClass::setval_gpio(int val) {
    digitalWrite(gpionum, val);
}

int GPIOClass::getval_gpio() {
    return digitalRead(gpionum);
}

int GPIOClass::get_gpionum() {

    return this->gpionum;

}