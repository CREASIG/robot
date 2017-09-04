/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Servo.h
 * Author: eric
 *
 * Created on 25 août 2017, 17:01
 */

#ifndef SERVO_H
#define SERVO_H

#include <cstring>
#include <string>

using namespace std;


class Servo {
public:
    Servo();
    Servo(const Servo& orig);
    
    /*
     Configuration du servo
     */
    void setConfiguration(char* config);
    
    /*
     Récupération de la config
     */
    const char* getConfiguration();
    
    /*
     Adresse d'accès à la carte
     */
    char* getAdresseCarte();
    void setAdresseCarte(char* adresse);
    
    /*
     Adresse d'accès au servo
     */
    char* getAdresseServo();
    void setAdresseServo(char* adresse);
    
    /*
     Code d'initialisation du servo (Angle que doit prendre le servo lors l'allumage du robot
     */
    char* getInitialisation();
    void setInitialisation(char* init);

    virtual ~Servo();
private:
    char* adressecarte;
    char* adresseservo;
    char* initialisation;
};

#endif /* SERVO_H */

