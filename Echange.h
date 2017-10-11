/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Echange.h
 * Author: eric
 *
 * Created on 3 octobre 2017, 20:57
 */

#ifndef ECHANGE_H
#define ECHANGE_H

#include <string>

using namespace std;

class Echange {
public:
    Echange();
    Echange(const Echange& orig);
    virtual ~Echange();

    string getTexte();
    void setTexte(string texte);
private:
    string texte;
};

#endif /* ECHANGE_H */

