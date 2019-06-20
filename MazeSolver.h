#ifndef MAZESOLVER_MAZESOLVER_H
#define MAZESOLVER_MAZESOLVER_H
#include "Maze.h"
#include <vector>
#include <queue>
#include <unordered_set>

class MazeSolver {
 public:
  explicit MazeSolver(Maze& m);
  bool Possible();

 private:
  Maze& m;
  bool found_end = false;
  std::deque<Node> open;
  std::vector<Node> closed;

  void SolveMaze(Node start);
  bool InOpen(Node& node);
  bool InClosed(Node& node);
};
#endif //MAZESOLVER_MAZESOLVER_H
