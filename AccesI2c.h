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
     
     */
    void ecrireRegistre8bit(int adresse, uint8_t valeur);
    int lectureRegistre8bit(int adresse);

void ecrireRegistre16bit(int adresse, __u16 valeur);    
private:
    int fichier;
};

#endif /* ACCESI2C_H */

