/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: e.vandevondele
 *
 * Created on 23 août 2017, 14:45
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

//#include "GPIOClass.h"
//#include "config.h"
//#include "AfficheurSimple.h"
//#include "Gyroscope.h"
#include "./servo/Servo.h"
#include "./servo/MG90D.h"


using namespace std;
//Config config;

/*
 * 
 */
int main(int argc, char** argv) {

    printf("debut du programme\n");

    AccesI2c accesi2c;

    Servo* s=new MG90D(&accesi2c, 0x6F, 0);
    int frequence = 50;
    s->setFrequence(frequence);
    while (true) {
//        s->setAngle(60);
//        usleep(2000000);
//        s->setAngle(-60);
//        usleep(2000000);
        int a = 0;
        cin >> a;
        s->setAngle(a);
    }
    //    Gyroscope g;

    /*
    AfficheurSimple aff;
    int i = 0;
    while (true) {
        aff.afficher(i);
        usleep(500000);
        i++;
        if (i == 10) {
            i = 0;
        }

    }
     */

    /*
        GPIOClass* gpio4 = new GPIOClass("6");
        gpio4->export_gpio(); //export GPIO4

        cout << " GPIO pins exported" << endl;

        gpio4->setdir_gpio("out"); // GPIO17 set to input
        bool val = true;
        while (1) {
            usleep(50000); // wait for 0.5 seconds
            if (val) {
                gpio4->setval_gpio("1");
                val = false;
            } else {
                gpio4->setval_gpio("0");
                val = true;
            }
        }
     */
    printf("fin\n");

    //system("coucou");




    return 0;
}

