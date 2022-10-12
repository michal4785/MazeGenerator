cmake_minimum_required(VERSION 3.22)
project(MazeGenerator)

set(CMAKE_CXX_STANDARD 14)

add_executable(MazeGenerator main.cpp Wall.cpp Wall.h Tile.cpp Tile.h Generator.cpp Generator.h Maze.cpp Maze.h)
