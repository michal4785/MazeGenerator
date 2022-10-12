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
        Maze(int rows, int columns);
        void printMaze();
        Wall& getWall(int y, int x);
        Tile& getTile(int y, int x);
        void visitTile(int y, int x);
        void ruinWall(int y, int x);
        static std::vector<int> getCoordOfWallBetweenTiles(std::vector<int> tile1, std::vector<int> tile2);
        void setTileOnThePath(int y, int x);
        bool areCoordsInside(int y, int x) const;
        bool allTilesVisited();
        int getRows() const;
        int getColumns() const;

    private:
        int columns;
        int rows;
        std::vector<Tile> path;
        std::vector<std::vector<Wall>> walls;
        std::vector<std::vector<Tile>> tiles;
};


#endif //MAZEGENERATOR_MAZE_H
