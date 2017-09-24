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
#include "Servo.h"
#include "nbproject/servo/MG90D.h"


using namespace std;
//Config config;

/*
 * 
 */
int main(int argc, char** argv) {

    printf("debut du programme\n");

    AccesI2c accesi2c;

    Servo* s=new MG90D(&accesi2c, 0x6F, 0);
    int i = 1750;
    int frequence = 50;
    int a = 0;
    s->setFrequence(frequence);
    int c = (0xFFF * 1) / 20;
    int d = (0xFFF * 2) / 20;
    c = 158;
    d = 500;
    while (true) {
        //        s.setFrequence(frequence);

        usleep(200000);
        cout << "fréquence=" << frequence << "  c=" << c << "  d=" << d << endl;
        s->setAngle(60);
        //d++;
        cout << c << endl;
        usleep(2000000);
        s->setAngle(-60);
        cout << d << endl;
        //        s.setValeur(2000, 0xFFF-2000);
        usleep(2000000);
        //        frequence ++;
        //        i+=10;
        //        cin >> a;
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

