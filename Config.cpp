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

#include <cstring>

#include "Config.h"

using namespace std;

Config::Config() {
    system("mkdir ~/robot/");
    fichier.open(( string(getenv("HOME"))+"/robot/config.cfg" ));
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
        std::ofstream fichier(( string(getenv("HOME"))+"/robot/config.cfg" ));
        if (fichier.is_open()) {
            servoLeft1="&dd";
            fichier << "ServoLeft1="<<servoLeft1<<"\n";
            fichier << "This is another line.\n";
            fichier.close();
            string b;
            b.append("cat " );
            b.append(getenv("HOME") );
            b.append("/robot/config.cfg" );
            system(b.c_str());
        }
}