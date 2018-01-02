/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestServo.h
 * Author: eric
 *
 * Created on 1 janvier 2018, 18:23
 */

#ifndef TESTSERVO_H
#define TESTSERVO_H

#include "AccesI2c.h"

class TestServo {
public:
    TestServo();
    
    void testerTousServos();

    void testerUnServoBoucle(int numero);    
    
    void testerUnServo(int numero, int angle);
    
    void testerParametresServo(int numero, int frequence,int numeromin);

    
    TestServo(const TestServo& orig);
    virtual ~TestServo();
private:
    AccesI2c* accesi2c;
};

#endif /* TESTSERVO_H */

