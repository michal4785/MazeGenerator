//
// Created by Michał on 09.10.2022.
//

#include "Wall.h"

Wall::Wall(int y, int x){
    this->y = y;
    this->x = x;
    this->isSet = false;
}
void Wall::set(){
    this->isSet = true;
}
void Wall::ruin(){
    this->isSet = false;
}
int Wall::getY(){
    return this->y;
}
int Wall::getX(){
    return this->x;
}

bool Wall::getState(){
    return isSet;
}