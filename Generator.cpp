//
// Created by Michał on 09.10.2022.
//

#include "Generator.h"

Maze Generator::generate(int y, int x){
    srand (time(NULL));
    Maze maze = Maze(y, x);
    return maze;
}
Maze Generator::generate(int y, int x, int seed){
    srand (seed);
    Maze maze = Maze(y, x);
    return maze;
}
std::vector<std::vector<int>> Generator::generatePotentialMoves(int currentY, int currentX){
    std::vector<std::vector<int>> potentialMoves;
    potentialMoves.push_back({currentY, currentX+1});
    potentialMoves.push_back({currentY, currentX-1});
    potentialMoves.push_back({currentY-1, currentX});
    potentialMoves.push_back({currentY+1, currentX});
    return potentialMoves;
}
bool Generator::forward(Maze &maze,std::vector<std::vector<int>> &tracker, int currentY, int currentX){
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
        std::vector<int> currentMove = moves.at(rand() % moves.size());
        tracker.push_back(currentMove);
        maze.visitTile(currentMove.at(0), currentMove.at(1));
        std::vector<int> lastMove = tracker.at(tracker.size()-2);
        std::vector<int> wallCoords = Maze::getCoordOfWallBetweenTiles(lastMove, currentMove);
        maze.ruinWall(wallCoords.at(0), wallCoords.at(1));
        return true;
    }
    else{
        return false;
    }
}
void Generator::backward(std::vector<std::vector<int>>& tracker){
    tracker.pop_back();
}
void Generator::updateCoords(std::vector<std::vector<int>> &tracker, int &y, int&x){
    y = tracker.at(tracker.size()-1).at(0);
    x = tracker.at(tracker.size()-1).at(1);
}
void Generator::backTracker(Maze &maze){
    int y, x;
    std::vector<std::vector<int>> tracker;
    // tracker.push_back(maze.getTile(0, 0));
    tracker.push_back({0, 0});
    maze.visitTile(0,0);
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
            for (std::vector<int> & i : tracker) {
                y = i.at(0);
                x = i.at(1);
                maze.setTileOnThePath(y, x);
            }
        }
    }

}