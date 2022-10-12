#include <iostream>
#include "Maze.h"
#include "Generator.h"


int main() {
    Generator generator = Generator();
    Maze maze = generator.generate(4, 4);
    generator.backTracker(maze);
    maze.printMaze();

    return 0;
}
