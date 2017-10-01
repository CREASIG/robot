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

//#include "config.h"
#include "Gyroscope.h"
#include "./servo/Servo.h"
#include "./servo/MG90D.h"


using namespace std;
//Config config;

/*
 * 
 */
int main(int argc, char** argv) {

    printf("debut du programme\n");

    
    //Création de l'objet donnat l'accès au port I2C
    AccesI2c *accesi2c =new AccesI2c();

    Gyroscope g(accesi2c,0x19);

    // Création de l'objet pour l'accès au servo 0 de la carte 6F
    Servo* s=new MG90D(accesi2c, 0x6F, 0);
    Servo* s1=new MG90D(accesi2c, 0x6F, 15);
    
    // fréquence du signal qui pilote le servo à 50hz
    s->setFrequence(50);
    while (true) {
        int a = 0;
        
        // Récupération de l'angle auprès de l'utilisateur
//        cin >> a;
        g.calcule();
        a=g.getAngleX();
        //Mise en place de l'angle
        s->setAngle(a);
        s1->setAngle(a*-1);
    }
    printf("fin\n");

    return 0;
}

