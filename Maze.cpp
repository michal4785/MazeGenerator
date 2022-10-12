//
// Created by Michał on 10.10.2022.
//

#include "Maze.h"

Maze::Maze(int columns, int rows){
    this->columns = columns;
    this->rows = rows;
    for (int i = 0; i < 2*rows+1; ++i) {
        std::vector<Wall> row;
        for (int j = 0; j < columns; ++j) {
            Wall wall = Wall(i, j);
            if(i == 0 || (i % 2 != 0 && j == 0)  || i == 2*rows){
                wall.set();
            }
            row.push_back(wall);
        }
        walls.push_back(row);
    }
    for (int i = 0; i < rows; ++i) {
        std::vector<Tile> row;
        for (int j = 0; j < columns; ++j) {
            row.push_back(Tile(i, j));
        }
        tiles.push_back(row);
    }
}


void Maze::printMaze(){
    for (int i = 0; i < 2*rows+1; ++i) {
        for (int j = 0; j < columns; ++j) {
            if(i % 2 == 0){
                std::cout<<"+";
                if(walls.at(i).at(j).getState()){
                    std::cout<<"---"; // printf("---");
                }
                else{
                    std::cout<<"   ";
                }
            }
            else{
                if(walls.at(i).at(j).getState()){
                    std::cout<<"|";
                }
                else{
                    std::cout<<" ";
                }
                if((tiles.at((i-1)/2).at(j)).getIsOnThePath()){
                    std::cout<<" . ";
                }
                else{
                    std::cout<<"   ";
                }

            }
        }
        if(i % 2 != 0){
            std::cout<<"|";
        }
        else{
            std::cout<<"+";
        }
        std::cout<<std::endl;
    }
}

Wall& Maze::getWall(int y, int x){
    return walls.at(y).at(x);
}

Tile& Maze::getTile(int y, int x){
    return tiles.at(y).at(x);
}
bool Maze::areCoordsInside(int y, int x){
    return y >= 0 && x >= 0 && y < rows && x < columns;
}

bool Maze::allTilesVisited(){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if(!tiles.at(i).at(j).isVisited()){
                return false;
            }
        }
    }
    return true;
}

int  Maze::getRows(){
    return rows;
}
int  Maze::getColumns(){
    return columns;
}
