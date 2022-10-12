//
// Created by Michał on 09.10.2022.
//

#ifndef MAZEGENERATOR_GENERATOR_H
#define MAZEGENERATOR_GENERATOR_H
#include "Tile.h"
#include <vector>
#include "Maze.h"
class Generator {
public:
    Generator()= default;
    Generator(int seed){
        this->seed = seed;
    }
    Maze generate(int y, int x){
         Maze maze = Maze(y, x);
         return maze;
    }
    std::vector<std::vector<int>> generatePotentialMoves(int currentY, int currentX){
        std::vector<std::vector<int>> potentialMoves;
        potentialMoves.push_back({currentY, currentX+1});
        potentialMoves.push_back({currentY, currentX-1});
        potentialMoves.push_back({currentY-1, currentX});
        potentialMoves.push_back({currentY+1, currentX});
        return potentialMoves;
    }
    bool forward(Maze &maze,std::vector<Tile> &tracker, int currentY, int currentX){
        std::vector<std::vector<int>> potentialMoves = generatePotentialMoves(currentY, currentX);
        std::vector<std::vector<int>> moves;
        for (std::vector<int> & potentialMove : potentialMoves) {
            int y = potentialMove.at(0);
            int x = potentialMove.at(1);
            if(maze.areCoordsInside(y, x)){
                if(!maze.getTile(y, x).isVisited()){
                    moves.push_back({y, x});
                }
            }
        }
        if(!moves.empty()){
            std::vector<int> move = moves.at(rand() % moves.size());
            tracker.push_back(maze.getTile(move.at(0), move.at(1)));
            tracker.at(tracker.size()-1).visit();
            return true;
        }
        else{
            return false;
        }
    }
    void backward(std::vector<Tile> &tracker){
        printf("TrackerSize: %d\n", tracker.size());
        tracker.pop_back();
    }
    void backTracker(Maze &maze){
        std::vector<Tile> tracker;
        tracker.push_back(maze.getTile(0, 0));
        while(!maze.allTilesVisited()){
            int y = tracker.at(tracker.size()-1).getY();
            int x = tracker.at(tracker.size()-1).getX();
            printf("Y: %d, X: %d\n", y, x);
            while(!forward(maze, tracker, y, x)){
                backward(tracker);
            }
            if(y == maze.getRows()-1 && x == maze.getColumns()-1){
                for (Tile & i : tracker) {
                    i.setOnThePath();
                }
                printf("Path! TrackerSize: %d\n", tracker.size());
                maze.printMaze();
            }
        }

    }
private:
    int seed;
};


#endif //MAZEGENERATOR_GENERATOR_H
