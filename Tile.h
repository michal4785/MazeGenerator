//
// Created by Michał on 09.10.2022.
//

#ifndef MAZEGENERATOR_TILE_H
#define MAZEGENERATOR_TILE_H


class Tile {
public:
    Tile(int y, int x);
    void setOnThePath();
    int getY();
    int getX();
    void visit();
    bool isVisited();
    bool getIsOnThePath();

private:
    int x;
    int y;
    bool isOnThePath;
    bool visited;

};


#endif //MAZEGENERATOR_TILE_H
