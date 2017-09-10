/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AfficheurSimple.cpp
 * Author: eric
 * 
 * Created on 9 septembre 2017, 13:13
 */

#include <iostream>

#include "AfficheurSimple.h"

AfficheurSimple::AfficheurSimple() {
    printf("initialisation afficheur\n");

    rclk = new GPIOClass("19");
    srlclk = new GPIOClass("5");
    ser = new GPIOClass("13");
    //    srlclr = new GPIOClass("6");

    rclk->export_gpio(); //export GPIO4
    rclk->setdir_gpio("out"); // GPIO17 set to input

    srlclk->export_gpio(); //export GPIO4
    srlclk->setdir_gpio("out"); // GPIO17 set to input

    ser->export_gpio(); //export GPIO4
    ser->setdir_gpio("out"); // GPIO17 set to input

}

AfficheurSimple::AfficheurSimple(const AfficheurSimple& orig) {
    printf("initialisation afficheur orig\n");
}

AfficheurSimple::~AfficheurSimple() {
}

void AfficheurSimple::afficher(int nombre){
    char caractere ;
    /*
     - 1
     haut gauche 2
     bas gauche 4
     bas 8
     bas droite 10
     haut droite 20
     haut 40
          
     */
    if(nombre == 0){
        caractere  = 0x7E;
    }else if(nombre == 1){
        caractere  = 0x30;
    }else if(nombre == 2){
        caractere  = 0x6d;
    }else if(nombre == 3){
        caractere  = 0x40+0X30+0X8+0x1;
    }else if(nombre == 4){
        caractere  = 0x2+0x1+0x30;
    }else if(nombre == 5){
        caractere  = 0x40+0x2+0x1+0x10+0x8;
    }else if(nombre == 6){
        caractere  = 0x2+0x4+0x8+0x10+0x1;
    }else if(nombre == 7){
        caractere  = 0x40+0x10+0x20;
    }else if(nombre == 8){
        caractere  = 0xFF;
    }else if(nombre == 9){
        caractere  = 0x1+0x2+0x40+0x10+0x20+0x8;
    }
        

    rclk->setval_gpio("0");
    ser->setval_gpio("0");
    for (int i = 0; i < 7; i++) {
        ser->setval_gpio(string(1,48+(caractere & 0x1)));
        rclk->setval_gpio("0");
        srlclk->setval_gpio("1");
        rclk->setval_gpio("1");
        srlclk->setval_gpio("0");
        caractere = caractere >> 0x1;
    }

}
