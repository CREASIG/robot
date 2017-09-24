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





#include "Servo.h"

Servo::Servo(AccesI2c *accesi2c, uint8_t numerocarte, uint8_t numeroservo) {

    this->adressecarte = numerocarte;
    this->adresseservo = numeroservo;
    this->accesservo = accesi2c;
    initialisation = (char*) "3";
    accesservo->selectionComposant(numerocarte);
    cout << "écriture dans __MODE2" << endl;
//    accesservo->ecrireRegistre8bit(__MODE2, __OUTDRV);
    cout << "écriture dans __MODE1" << endl;
    accesservo->ecrireRegistre8bit(__MODE1, __ALLCALL);
    usleep(5000);
    cout << "Lecture dans __MODE1" << endl;
    uint8_t modele = accesservo->lectureRegistre8bit(__MODE1);
    printf("mode1=%x\n", modele);
    cout << "écriture dans __MODE1" << endl;
    accesservo->ecrireRegistre8bit(__MODE1, modele | __SLEEP);
    usleep(5000);
    accesservo->ecrireRegistre8bit(__MODE1, 0x1);
    usleep(5000);
    //setFrequence(60);

}

Servo::Servo(const Servo& orig) {
}

Servo::~Servo() {
}

uint Servo::getValeur() {
    return valeur;
}

void Servo::setValeur(uint on, uint off) {

    accesservo->selectionComposant(adressecarte);
    accesservo->ecrireRegistre8bit(__LED0_ON_L + 4 * adresseservo, on & 0xFF);
    accesservo->ecrireRegistre8bit(__LED0_ON_H + 4 * adresseservo, on >> 8);
    accesservo->ecrireRegistre8bit(__LED0_OFF_L + 4 * adresseservo, off & 0xFF);
    accesservo->ecrireRegistre8bit(__LED0_OFF_H + 4 * adresseservo, off >> 8);

}

void Servo::setAllValeur(uint on, uint off) {
    accesservo->selectionComposant(this->adressecarte);
    accesservo->ecrireRegistre8bit(__ALL_LED_ON_L, on & 0xFF);
    accesservo->ecrireRegistre8bit(__ALL_LED_ON_H, on >> 8);
    accesservo->ecrireRegistre8bit(__ALL_LED_OFF_L, off & 0xF);
    accesservo->ecrireRegistre8bit(__ALL_LED_OFF_H, off >> 8);
}

void Servo::setFrequence(int frequence) {


    float calculvaleur = 25000000;
    calculvaleur /= (4096*(float) frequence);
    calculvaleur -= 1;
    calculvaleur = floorf(calculvaleur);

    int ancienne = accesservo->lectureRegistre8bit(__MODE1);
    while ((ancienne & 0x80) > 0) {
        accesservo->ecrireRegistre8bit(__MODE1, ancienne & 0xEF);
        usleep(5000);
        ancienne = accesservo->lectureRegistre8bit(__MODE1);
    }
    accesservo->ecrireRegistre8bit(__MODE1, ancienne | __SLEEP);

    usleep(5000);
    accesservo->ecrireRegistre8bit(__PRESCALE, (uint) calculvaleur & 0xFF);
    //printf("freq=%X  valeur=%X \n", frequence, calculvaleur);
    usleep(500);
    accesservo->ecrireRegistre8bit(__MODE1, (ancienne & 0xEF) | 0X80);
    while ((ancienne & 0x80) > 0) {
        usleep(5000);
        accesservo->ecrireRegistre8bit(__MODE1, ancienne & 0xEF);
        ancienne = accesservo->lectureRegistre8bit(__MODE1);
    }
    usleep(5000);

}

/*
 Configuration du servo
 */
void Servo::setConfiguration(char* config) {
    std::string token, conf(config);
    //strcpy(adressecarte, conf.substr(0, conf.find_first_of("|")).c_str());
    conf = conf.substr(conf.find_first_of("|") + 1);
    //strcpy(adresseservo, conf.substr(0, conf.find_first_of("|")).c_str());
    conf = conf.substr(conf.find_first_of("|") + 1);
    //strcpy(initialisation, conf.substr(0, conf.find_first_of("|")).c_str());
    conf = conf.substr(conf.find_first_of("|") + 1);
}

/*
 Récupération de la config
 */
const char* Servo::getConfiguration() {
    std::string conf;
    //conf += std::string(adressecarte);
    conf += "|";
    conf += adresseservo;
    conf += "|";
    conf += initialisation;
    conf += "|";
    return "conf.c_str()";
}

/*
 Adresse d'accès à la carte
 */
int Servo::getAdresseCarte() {
    return adressecarte;
}

void Servo::setAdresseCarte(int adresse) {
    adressecarte = adresse;
}

/*
 Adresse d'accès au servo
 */
int Servo::getAdresseServo() {
    return adresseservo;
}

void Servo::setAdresseServo(int adresse) {
    adresseservo = adresse;
}

/*
 Code d'initialisation du servo (Angle que doit prendre le servo lors l'allumage du robot
 */
char* Servo::getInitialisation() {
    return initialisation;
}

void Servo::setInitialisation(char* init) {
    initialisation = init;
}
