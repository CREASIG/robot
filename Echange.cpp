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

#include <iostream>

#include "Echange.h"

Echange::Echange() {
    this->texte = "";
    this->avancer=0;
    this->reculer=0;
    this->gauche=0;
    this->droite=0;
}

Echange::Echange(const Echange& orig) {
}

Echange::~Echange() {
}

string Echange::getTexte() {
    return texte;
}

void Echange::setTexte(string texte1) {
    this->texte = texte1;
}

string Echange::getInformation() {
    return "{}";
}

string Echange::getDebug() {
    string texte = "{\"liste\":[";
    for (int i = log.size(); i > 0; --i) {
        if (i < log.size())texte += ",";
        texte += "{\"texte\": \"" + log[i] + "\"}";
    }
    texte += "]}";
    return texte;
}

string Echange::setParametre(string parametre) {
    string nom = parametre.substr(0, parametre.find(" "));
    string valeur = parametre.substr(parametre.find(" "), parametre.size() - parametre.find(" "));


    if (nom == string("avancer")) {
        setAvancer(stoi(valeur));
    
    } else if (nom == string("reculer")) {
        setReculer(stoi(valeur));
    } else if (nom == string("gauche")) {
        setGauche(stoi(valeur));
    } else if (nom == string("droite")) {
        setDroite(stoi(valeur));
    }
    return "{}";
}

void Echange::setAvancer(int a) {

    this->avancer = a;
}

int Echange::getAvancer() {

    return avancer;
}

void Echange::setReculer(int a) {

    this->reculer = a;
}

int Echange::getReculer() {

    return reculer;
}

void Echange::setGauche(int a) {

    this->gauche = a;
}

int Echange::getGauche() {

    return gauche;
}

void Echange::setDroite(int a) {

    this->droite = a;
}

int Echange::getDroite() {

    return droite;
}

void Echange::addLog(string message) {
    log.push_back(message);
    if (log.size() > TAILLE_MAX_ERROR) {

        log.erase(log.begin());
    }
}

vector<string> Echange::getLogs() {
    return this->log;
}