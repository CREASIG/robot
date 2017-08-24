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

#include "Config.h"

using namespace std;

Config::Config() {
    system("mkdir ~/robot/");
    fichier.open(( string(getenv("HOME"))+"/robot/config.cfg" ));
    if (fichier.good()) {
        printf("Config trouvée");

    } else {
        std::ofstream fichier(( string(getenv("HOME"))+"/robot/config.cfg" ));
        if (fichier.is_open()) {
            fichier << "This is a line.\n";
            fichier << "This is another line.\n";
            fichier.close();
        }
        printf("Config non trouvée\n");
    }
}

Config::Config(const Config& orig) {
}

Config::~Config() {
    fichier.close();
}

