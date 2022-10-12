//
// Created by Michał on 09.10.2022.
//

#include "Tile.h"

Tile::Tile(int y, int x){
    this->y = y;
    this->x = x;
    this->isOnThePath = false;
    this->visited = false;
}
void Tile::setOnThePath(){
    this->isOnThePath = true;
}
int Tile::getY(){
    return this->y;
}
int Tile::getX(){
    return this->x;
}


void Tile::visit(){
    visited = true;
}

bool Tile::isVisited(){
    return visited;
}


bool Tile::getIsOnThePath(){
    return isOnThePath;
}