/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Camera.cpp
 * Author: eric
 * 
 * Created on 17 octobre 2017, 08:28
 */

#include "Camera.h"

Camera::Camera(Echange *echange) {
    this->echange = echange;
    system("killall uv4l");
    system("uv4l --driver raspicam --auto-video_nr --encoding h264 --width 640 --height 480 --enable-server on --server-option '--port=9000'");
}

Camera::Camera(const Camera& orig) {
}

Camera::~Camera() {
    system("killall uv4l");
}

void Camera::lancer(){
    
}
