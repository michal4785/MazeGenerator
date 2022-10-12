//
// Created by Michał on 10.10.2022.
//

#ifndef MAZEGENERATOR_MAZE_H
#define MAZEGENERATOR_MAZE_H
#include <vector>
#include "Wall.h"
#include "Tile.h"
#include <iostream>

class Maze {


    public:
        Maze(int columns, int rows);
        void printMaze();
        Wall& getWall(int y, int x);
        Tile& getTile(int y, int x);
        bool areCoordsInside(int y, int x);
        bool allTilesVisited();
        int getRows();
        int getColumns();

    private:
        int columns;
        int rows;
        std::vector<Tile> path;
        std::vector<std::vector<Wall>> walls;
        std::vector<std::vector<Tile>> tiles;
};


#endif //MAZEGENERATOR_MAZE_H
