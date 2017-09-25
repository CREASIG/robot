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
#include <iosfwd>

#include <iostream>

#include "../AccesI2c.h"

#define __MODE1 0x00
#define __MODE2 0x01
#define __SUBADR1 0x02
#define __SUBADR2 0x03
#define __SUBADR3 0x04
#define __PRESCALE 0xFE
#define __LED0_ON_L 0x06
#define __LED0_ON_H 0x07
#define __LED0_OFF_L 0x08
#define __LED0_OFF_H 0x09
#define __ALL_LED_ON_L 0xFA
#define __ALL_LED_ON_H 0xFB
#define __ALL_LED_OFF_L 0xFC
#define __ALL_LED_OFF_H 0xFD


#define __RESTART 0x80
#define __SLEEP 0x10
#define __ALLCALL 0x01
#define __INVERT 0x10
#define __OUTDRV 0x04
#define __RESTART 0x80



using namespace std;

class Servo {
public:
    Servo(AccesI2c *accesi2c, uint8_t numerocarte, uint8_t numeroservo);
    Servo(const Servo& orig);

    uint getValeur();
    void setValeur(uint on, uint off);
    void setAllValeur(uint on, uint off);
    
    virtual void setAngle(int angle)=0;

    void setFrequence(int frequence);

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
    int getAdresseCarte();
    void setAdresseCarte(int adresse);

    /*
     Adresse d'accès au servo
     */
    int getAdresseServo();
    void setAdresseServo(int adresse);

    /*
     Code d'initialisation du servo (Angle que doit prendre le servo lors l'allumage du robot
     */
    char* getInitialisation();
    void setInitialisation(char* init);

    virtual ~Servo();
private:
    uint8_t adressecarte;
    uint8_t adresseservo;
    char* initialisation;
    AccesI2c *accesservo;
    uint valeur;
};

#endif /* SERVO_H */

