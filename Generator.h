//
// Created by Michał on 09.10.2022.
//

#ifndef MAZEGENERATOR_GENERATOR_H
#define MAZEGENERATOR_GENERATOR_H
#include "Tile.h"
#include <vector>
#include "Maze.h"
#include <time.h>
class Generator {
public:
    Generator()= default;
    static Maze generate(int y, int x);
    static Maze generate(int y, int x, int seed);
    static std::vector<std::vector<int>> generatePotentialMoves(int currentY, int currentX);
    static bool forward(Maze &maze,std::vector<std::vector<int>> &tracker, int currentY, int currentX);
    static void backward(std::vector<std::vector<int>>& tracker);
    static void updateCoords(std::vector<std::vector<int>> &tracker, int &y, int&x);
    static void backTracker(Maze &maze);
};


#endif //MAZEGENERATOR_GENERATOR_H
