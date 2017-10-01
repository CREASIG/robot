/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AccesI2c.cpp
 * Author: eric
 * 
 * Created on 22 septembre 2017, 18:06
 */

#include <stdint.h>

#include "AccesI2c.h"
#include "servo/Servo.h"

AccesI2c::AccesI2c() {
    char nomfichier[20];
    sprintf(nomfichier, "/dev/i2c-%d", 1);
    this->fichier = open(nomfichier, O_RDWR);
    if (this->fichier < 0) {
        printf("Impossible de sélectionner le bus I2C !");
        exit(1);
    }

}

AccesI2c::AccesI2c(const AccesI2c& orig) {
}

AccesI2c::~AccesI2c() {
}

void AccesI2c::selectionComposant(int adresse) {
    this->adresse = adresse;
    if (ioctl(this->fichier, I2C_SLAVE, adresse) < 0) {
        printf("Je n'ai pas réussi à accéder au composant I2C.");
    }
}

void AccesI2c::ecrireRegistre8bit(int adresseregistre, __u8 valeur) {
    int result = i2c_smbus_write_byte_data(this->fichier, adresseregistre, valeur);
    if (result < 0) {
        printf("Echec d'écriture dans le registre I2C à l'adresse %X du composant %X.",adresseregistre,this->adresse);
        exit(1);
    }
}

int AccesI2c::lectureRegistre8bit(int adresseregistre) {
    int result = i2c_smbus_read_byte_data(this->fichier, adresseregistre);
    if (result == -1) {
        printf("Echec de lecture dans le registre I2C à l'adresse %X du composant %X.",adresseregistre,this->adresse);
        exit(1);
    }
    return result;
}

void  AccesI2c::lectureBlock(uint8_t adresseregistre, uint8_t taille, uint8_t *donnee)
{
    int resultat = i2c_smbus_read_i2c_block_data(fichier, adresseregistre, taille, donnee);
    if (resultat != taille)
    {
        printf("Echec de lecture du block de l'I2C à l'adresse %X.",adresseregistre);
        exit(1);
    }
}
