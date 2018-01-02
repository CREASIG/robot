/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestServo.cpp
 * Author: eric
 * 
 * Created on 1 janvier 2018, 18:23
 */

#include "TestServo.h"
#include "servo/MG90D.h"

TestServo::TestServo() {
    accesi2c = new AccesI2c();
}

void TestServo::testerTousServos() {
    for (int i = 0; i < 16; i++) {
        printf("test servo numéro:%d\n", i);
        MG90D servo(accesi2c, 0x40, i);
        servo.setFrequence(60);

        servo.setAngle(-90);
        usleep(500000);
        servo.setAngle(90);
        usleep(500000);


        if (i == 15) {
            i = -1;
        }
    }
}

void TestServo::testerUnServoBoucle(int numero) {
    printf("test servo numéro:%d\n", numero);
    MG90D servo(accesi2c, 0x40, numero);
    servo.setFrequence(60);
    while (true) {
        servo.setAngle(-90);
        usleep(500000);
        servo.setAngle(90);
        usleep(500000);
    }
}

void TestServo::testerUnServo(int numero, int angle) {
    printf("numero:%d  angle=%d\n", numero, angle);
    MG90D servo(accesi2c, 0x40, numero);
    servo.setFrequence(60);
    servo.setAngle(angle);
}

void TestServo::testerParametresServo(int numero, int frequence, int numeromin) {
    printf("numero:%d  frequence=%d numeromin=%d\n", numero, frequence, numeromin);
    MG90D servo(accesi2c, 0x40, numero);
    servo.setFrequence(frequence);
    servo.setValeur(numeromin);
}

TestServo::TestServo(const TestServo& orig) {
}

TestServo::~TestServo() {
}

