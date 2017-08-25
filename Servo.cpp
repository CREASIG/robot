/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Servo.cpp
 * Author: eric
 * 
 * Created on 25 août 2017, 17:01
 */

#include <iosfwd>
#include <string>
#include <string.h>

#include "Servo.h"

Servo::Servo() {
    adressecarte=(char*)" ";
    adresseservo=(char*)" ";
    initialisation=(char*)"  ";

}

Servo::Servo(const Servo& orig) {
}

Servo::~Servo() {
}

    /*
     Configuration du servo
     */
    void Servo::setConfiguration(char* config){
        std::string token, conf( config);
        strcpy(adressecarte , conf.substr(0,conf.find_first_of("|")).c_str());
        conf = conf.substr(conf.find_first_of("|") + 1);
        strcpy(adresseservo , conf.substr(0,conf.find_first_of("|")).c_str());
        conf = conf.substr(conf.find_first_of("|") + 1);
        strcpy(initialisation , conf.substr(0,conf.find_first_of("|")).c_str());
        conf = conf.substr(conf.find_first_of("|") + 1);
    }
    
    /*
     Récupération de la config
     */
    const char* Servo::getConfiguration(){
        std::string conf;
        conf.append( adressecarte );
        conf.append( "|" );
        conf.append( adresseservo );
        conf.append( "|" );
        conf.append( initialisation );
        conf.append( "|" );
        return conf.c_str();
    }
    
    /*
     Adresse d'accès à la carte
     */
    char* Servo::getAdresseCarte(){
        return adressecarte;
    }
    
    
    void Servo::setAdresseCarte(char* adresse){
        adressecarte=adresse;
    }
    
    /*
     Adresse d'accès au servo
     */
    char* Servo::getAdresseServo(){
        return adresseservo;
    }
    
    void Servo::setAdresseServo(char* adresse){
        adresseservo=adresse;
    }
    
    /*
     Code d'initialisation du servo (Angle que doit prendre le servo lors l'allumage du robot
     */
    char* Servo::getInitialisation(){
        return initialisation;
    }
    
    
    void Servo::setInitialisation(char* init){
        initialisation=init;
    }
