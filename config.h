/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Config.h
 * Author: e.vandevondele
 *
 * Created on 23 août 2017, 15:01
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "Servo.h"


#include <ios>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>


class Config {
public:
    Config();
    Config(const Config& orig);
    virtual ~Config();
    void generateConfig();

private:
    Servo servoGaucheRotationCuisse;
    Servo servoGaucheAvancerCuisse;
    Servo servoGaucheTranslationCuisse;
    Servo servoGaucheGenoux;
    Servo servoGaucheRotationChevilleAvant;
    Servo servoGaucheRotationChevilleCote;

    Servo servoDroitRotationCuisse;
    Servo servoDroitAvancerCuisse;
    Servo servoDroitTranslationCuisse;
    Servo servoDroitGenoux;
    Servo servoDroitRotationChevilleAvant;
    Servo servoDroitRotationChevilleCote;
    std::ifstream fichier;

};

#endif /* CONFIG_H */

