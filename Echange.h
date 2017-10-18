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

#define TAILLE_MAX_ERROR    100

#include <string>
#include <vector>

using namespace std;

class Echange {
public:
    Echange();
    Echange(const Echange& orig);
    virtual ~Echange();

    string getTexte();
    void setTexte(string texte);

    string getInformation();
    string getDebug();
    string setParametre(string parametre);

    void setAvancer(int a);
    int getAvancer();
    void setReculer(int a);
    int getReculer();
    void setGauche(int a);
    int getGauche();
    void setDroite(int a);
    int getDroite();

    void addLog(string log);
    vector<string> getLogs();
    
    
private:
    string texte;
    int avancer;
    int reculer;
    int gauche;
    int droite;
    vector <string> log;
    
};

#endif /* ECHANGE_H */

