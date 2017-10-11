/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Serveur.h
 * Author: eric
 *
 * Created on 5 octobre 2017, 13:27
 */

#ifndef SERVEUR_H
#define SERVEUR_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "Echange.h"



class Serveur {
public:
    Serveur(Echange *echange);
    Serveur(const Serveur& orig);
    virtual ~Serveur();
private:
Echange* echange;
};

#endif /* SERVEUR_H */

