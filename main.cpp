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

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


#include <pthread.h>
//#include "config.h"
#include "Gyroscope.h"
#include "./servo/Servo.h"
#include "./servo/MG90D.h"
#include "Echange.h"
#include "Serveur.h"
#include "Camera.h"
#include "Marche.h"


using namespace std;
//Config config;

/*
 * 
 */


void *marche(void * echange1) {
    
//Gyroscope g(accesi2c, 0x68);
    Marche marche((Echange *)echange1);

/*
//Création de l'objet donnat l'accès au port I(Echange *)2C

Gyroscope g(accesi2c, 0x19);

// Création de l'objet pour l'accès au servo 0 de la carte 6F
Servo* s = new MG90D(accesi2c, 0x6F, 0);
Servo* s1 = new MG90D(accesi2c, 0x6F, 15);

// fréquence du signal qui pilote le servo à 50hz
s->setFrequence(50);
while (true) {
    int a = 0;

    // Récupération de l'angle auprès de l'utilisateur
    string texte;  
    cin >> texte;
    echange->setTexte(texte);
    g.calcule();
    a = g.getAngleX();
    //Mise en place de l'angle
    s->setAngle(a);
    s1->setAngle(a*-1);
}
 */
}

void *camera(void * echange1) {
    Echange* echange2;
    echange2 = (Echange *) echange1;
    Camera* camera = new Camera(echange2);
}

void *serveur(void * echange1) {
    Echange* echange2;
    echange2 = (Echange *) echange1;
    Serveur* s = new Serveur(echange2);
}

int main(int argc, char** argv) {

    printf("debut du programme\n");

    pthread_t tacheserveur;
    pthread_t tachemarche;
    pthread_t tachecamera;

    printf("fin\n");

    Echange echange;

//    pthread_create(&tacheserveur, NULL, serveur, (void *) &echange);
    pthread_create(&tachemarche, NULL, marche, (void *) &echange);
//    pthread_create(&tachecamera, NULL, camera, (void *) &echange);

    
    while (true);
    return 0;
}
