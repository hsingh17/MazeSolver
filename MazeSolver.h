#ifndef MAZESOLVER_MAZESOLVER_H
#define MAZESOLVER_MAZESOLVER_H
#include "Maze.h"
#include <vector>

class MazeSolver {
 public:
  explicit MazeSolver(Maze& m);
  bool Possible();

 private:
  Maze& m;
  bool found_end = false;
  std::vector<std::pair<int, int>> visited;

  void SolveMaze(std::pair<int, int> v);
  bool Visited(std::pair<int, int> v);

};
#endif //MAZESOLVER_MAZESOLVER_H
