#include <iostream>
#include "Maze.h"
#include "Generator.h"
#include <string>
bool isInteger(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


int main(int argc, char** argv) {
    if(argc < 3 || argc > 4){
        std::cout<<"invalid parameter list"<<std::endl;
        return 0;
    }
    Generator generator = Generator();
    if(!isInteger(argv[1]) || !isInteger(argv[2])){
        std::cout<<"invalid parameter list"<<std::endl;
        return 0;
    }
    if(argc == 4){
        if(!isInteger(argv[3])){
            std::cout<<"invalid parameter list"<<std::endl;
            return 0;
        }
    }
    if(argc == 4){
        Maze maze = generator.generate(std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]));
        generator.backTracker(maze);
        maze.printMaze();
    }
    else{
        Maze maze = generator.generate(std::stoi(argv[1]), std::stoi(argv[2]));
        generator.backTracker(maze);
        maze.printMaze();
    }

    return 0;
}
