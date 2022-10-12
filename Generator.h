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
    bool forward(Maze &maze,std::vector<std::vector<int>> &tracker, int currentY, int currentX){
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
            srand (time(NULL));
            std::vector<int> move = moves.at(rand() % moves.size());
            tracker.push_back(move);
            maze.visitTile(move.at(0), move.at(1));
            return true;
        }
        else{
            return false;
        }
    }
    void backward(std::vector<std::vector<int>>& tracker){
        printf("TrackerSize: %d\n", tracker.size());
        tracker.pop_back();
    }
    void updateCoords(std::vector<std::vector<int>> &tracker, int &y, int&x){
        y = tracker.at(tracker.size()-1).at(0);
        x = tracker.at(tracker.size()-1).at(1);
    }
    void backTracker(Maze &maze){
        int y, x;
        std::vector<std::vector<int>> tracker;
        // tracker.push_back(maze.getTile(0, 0));
        tracker.push_back({0, 0});
        printf("%d\n", maze.getTile(0, 0).isVisited());
        while(!(maze.allTilesVisited())){
            updateCoords(tracker, y, x);
            // printf("Y: %d, X: %d\n", y, x);
            while(!forward(maze, tracker, y, x)){
                backward(tracker);
                updateCoords(tracker, y, x);
            }
            updateCoords(tracker, y, x);
            if(y == maze.getRows()-1 && x == maze.getColumns()-1){
                // printf("\nPath! TrackerSize: %d\n", tracker.size());
                for (int i = 0; i < tracker.size(); ++i) {
                    y = tracker.at(i).at(0);
                    x = tracker.at(i).at(1);
                    maze.setTileOnThePath(y, x);
                }
            }
        }

    }
private:
    int seed;
};


#endif //MAZEGENERATOR_GENERATOR_H
