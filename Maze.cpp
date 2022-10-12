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
void Maze::visitTile(int y, int x){
    tiles.at(y).at(x).visit();
}

std::vector<int> Maze::getCoordOfWallBetweenTiles(std::vector<int> tile1, std::vector<int> tile2){
    int y;
    int x = tile1.at(1);
    if(tile1.at(0) == tile2.at(0)){
        y = (tile1.at(0)-1)/2;
    }
    else if(tile1.at(1) == tile2.at(1)){

    }
    else{
        throw std::exception("These tiles have not a shared wall!\n");
    }
    return {y, x};
}

void Maze::setTileOnThePath(int y, int x){
    tiles.at(y).at(x).setOnThePath();
}
bool Maze::areCoordsInside(int y, int x){
    return y >= 0 && x >= 0 && y < rows && x < columns;
}

bool Maze::allTilesVisited(){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if(!(tiles.at(i).at(j).isVisited())){
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
