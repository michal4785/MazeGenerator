//
// Created by Michał on 09.10.2022.
//

#ifndef MAZEGENERATOR_WALL_H
#define MAZEGENERATOR_WALL_H


class Wall {
public:
    Wall(int y, int x);
    void set();
    void ruin();
    int getY();
    int getX();
    bool getState();
private:
    int y;
    int x;
    bool isSet;
};


#endif //MAZEGENERATOR_WALL_H
