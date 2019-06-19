#include "Maze.h"
#include "MazeSolver.h"
#include <iostream>

int main(int argc, char* argv[]) {
  // Driver code for maze solver
  int test;
  std::cin >> test;
  Maze maze(argv[1]);
  MazeSolver solve(maze);
  if (solve.Possible())
    maze.UpdateMaze(argv[2]);
  else
    std::cout << "Maze is not solvable!" << std::endl;
  return 0;
}