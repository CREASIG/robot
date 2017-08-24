/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Config.h
 * Author: e.vandevondele
 *
 * Created on 23 août 2017, 15:01
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <ios>
#include <fstream>
#include <cstdio>

class Config {
public:
    Config();
    Config(const Config& orig);
    virtual ~Config();
    void generateConfig();

private:
    char* servoLeft1;
    std::ifstream fichier;

};

#endif /* CONFIG_H */

