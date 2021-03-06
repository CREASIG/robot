/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AccesI2c.h
 * Author: eric
 *
 * Created on 22 septembre 2017, 18:06
 */

#ifndef ACCESI2C_H
#define ACCESI2C_H

#include <unistd.h>    //Needed for I2C port
#include <fcntl.h>    //Needed for I2C port
#include <sys/ioctl.h>   //Needed for I2C port
#include <linux/i2c-dev.h>  //Needed for I2C port
#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

class AccesI2c {
public:
    AccesI2c();
    AccesI2c(const AccesI2c& orig);
    virtual ~AccesI2c();

    /*
     Choisir le composant I2C
     */
    void selectionComposant(int adresse);

    /*
     écrire dans le registre de la carte une valeur de 8bit à l'adresse indiquée
     * 
     * Paramètres :
     * int adresse : adresse du registre
     * uint8_t valeur : valeur
     */
    void ecrireRegistre8bit(int adresseregistre, uint8_t valeur);

    /*
     * Récupère la valeur dans le registre de la carte à l'adresse indiquée
     * 
     * Paramètres :
     * int adresse : adresse du registre
     */
    int lectureRegistre8bit(int adresseregistre);
    
    /*
     * Récupère un ensemble de valeurs dans le registre de la carte à l'adresse indiquée
     * 
     * Paramètres :
     * int adresse : adresse du registre
     * uint_t taille : nombre d'octets à récupérer
     * uint8_t *donnee : adresse du début du tableau
     */
    void lectureBlock(uint8_t adresseregistre, uint8_t taille, uint8_t *donnee);

void ecrireRegistre16bit(int adresse, __u16 valeur);    
private:
    int fichier;
    int adresse;
};

#endif /* ACCESI2C_H */

