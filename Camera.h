/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.h
 * Author: eric
 *
 * Created on 17 octobre 2017, 08:28
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "Echange.h"


class Camera {
public:
    Camera(Echange *echange);
    Camera(const Camera& orig);
    virtual ~Camera();
    
    void lancer();
private:
    Echange *echange;
};

#endif /* CAMERA_H */

