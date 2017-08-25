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

using namespace std;

Config::Config() {
    system("mkdir ~/robot/");
    fichier.open(( string(getenv("HOME"))+"/robot/config.cfg" ).c_str(),ios_base::in);
    if (fichier.good()) {
        printf("Config trouvée");

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

void Config::generateConfig(){
        std::ofstream fichier(( string(getenv("HOME"))+"/robot/config.cfg" ).c_str(),ofstream::out);
        if (fichier.is_open()) {
            fichier.write(servoGaucheRotationCuisse.getConfiguration(),sizeof(servoGaucheRotationCuisse.getConfiguration()));
            fichier << "servoGaucheRotationCuisse="<<servoGaucheRotationCuisse.getConfiguration()<<"\n";
            fichier << "servoGaucheAvancerCuisse="<<servoGaucheAvancerCuisse.getConfiguration()<<"\n";
            fichier << "servoGaucheTranslationCuisse="<<servoGaucheTranslationCuisse.getConfiguration()<<"\n";
            fichier << "servoGaucheGenoux="<<servoGaucheGenoux.getConfiguration()<<"\n";
            fichier << "servoGaucheRotationChevilleAvant="<<servoGaucheRotationChevilleAvant.getConfiguration()<<"\n";
            fichier << "servoGaucheRotationChevilleCote="<<servoGaucheRotationChevilleCote.getConfiguration()<<"\n";
            fichier << "servoDroitRotationCuisse="<<servoDroitRotationCuisse.getConfiguration()<<"\n";
            fichier << "servoDroitAvancerCuisse="<<servoDroitAvancerCuisse.getConfiguration()<<"\n";
            fichier << "servoDroitTranslationCuisse="<<servoDroitTranslationCuisse.getConfiguration()<<"\n";
            fichier << "servoDroitGenoux="<<servoDroitGenoux.getConfiguration()<<"\n";
            fichier << "servoDroitRotationChevilleAvant="<<servoDroitRotationChevilleAvant.getConfiguration()<<"\n";
            fichier << "servoDroitRotationChevilleCote="<< (string)servoDroitRotationChevilleCote.getConfiguration()<<"\n";
            fichier.close();
            string b;
            b.append("cat " );
            b.append(getenv("HOME") );
            b.append("/robot/config.cfg" );
            system(b.c_str());
        }
}