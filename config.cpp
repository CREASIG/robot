/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Config.cpp
 * Author: e.vandevondele
 * 
 * Created on 23 août 2017, 15:01
 */


#include "config.h"

Config::Config() {
    system("mkdir ~/robot/");
    ifstream fichier((string(getenv("HOME")) + "/robot/config.cfg").c_str());
    if (fichier.good()) {
        printf("Config trouvée");
        string ligne;
        while (getline(fichier, ligne)) { // tant que l'on peut mettre la ligne dans "contenu"
            lectureConfig(ligne);
        }
    } else {
        printf("Config non trouvée\n");
    }
}

Config::Config(const Config& orig) {
}

Config::~Config() {
    generateConfig();
    fichier.close();
}

void Config::lectureConfig(string config) {
    string servoconf = config.substr(0, config.find_first_of("="));
    string texte = config.substr(config.find_first_of("=")+1,config.length()-config.find_first_of("=") ).c_str();
    cout << servoconf  <<"---"<<  texte << endl;
}

void Config::generateConfig() {
    std::ofstream fichier((string(getenv("HOME")) + "/robot/config.cfg").c_str(), ofstream::out);
    if (fichier.is_open()) {
//        fichier.write(servoGaucheRotationCuisse.getConfiguration(), sizeof (servoGaucheRotationCuisse.getConfiguration()));
        fichier << "servoGaucheRotationCuisse=" << servoGaucheRotationCuisse.getConfiguration() << "\n";
        fichier << "servoGaucheAvancerCuisse=" << servoGaucheAvancerCuisse.getConfiguration() << "\n";
        fichier << "servoGaucheTranslationCuisse=" << servoGaucheTranslationCuisse.getConfiguration() << "\n";
        fichier << "servoGaucheGenoux=" << servoGaucheGenoux.getConfiguration() << "\n";
        fichier << "servoGaucheRotationChevilleAvant=" << servoGaucheRotationChevilleAvant.getConfiguration() << "\n";
        fichier << "servoGaucheRotationChevilleCote=" << servoGaucheRotationChevilleCote.getConfiguration() << "\n";
        fichier << "servoDroitRotationCuisse=" << servoDroitRotationCuisse.getConfiguration() << "\n";
        fichier << "servoDroitAvancerCuisse=" << servoDroitAvancerCuisse.getConfiguration() << "\n";
        fichier << "servoDroitTranslationCuisse=" << servoDroitTranslationCuisse.getConfiguration() << "\n";
        fichier << "servoDroitGenoux=" << servoDroitGenoux.getConfiguration() << "\n";
        fichier << "servoDroitRotationChevilleAvant=" << servoDroitRotationChevilleAvant.getConfiguration() << "\n";
        fichier << "servoDroitRotationChevilleCote=" << servoDroitRotationChevilleCote.getConfiguration() << "\n";
        fichier.close();
        string b;
//        b.append("cat ");
//        b.append(getenv("HOME"));
//        b.append("/robot/config.cfg");
        system(b.c_str());
    }
}