/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Echange.cpp
 * Author: eric
 * 
 * Created on 3 octobre 2017, 20:57
 */

#include "Echange.h"

Echange::Echange() {
    this->texte="";
}

Echange::Echange(const Echange& orig) {
}

Echange::~Echange() {
}

string Echange::getTexte(){
    return texte;
}

void Echange::setTexte(string texte1){
    this->texte=texte1;
}