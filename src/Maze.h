#ifndef MAZESOLVER_MAZE_H
#define MAZESOLVER_MAZE_H
#include "Node.h"
#include <vector>
#include <memory>

class Maze {
 public:
  explicit Maze(char* file_path);

  const std::vector<std::vector<Node>>& GetMaze() const;
  std::vector<Node> Adj(Node& v);

  const int Row() const;
  const int Col() const;
  Node& Start();
  Node& End();

  void UpdateMaze(const char* new_file);

  Node& operator()(int x, int y);

 private:
  std::vector<std::vector<Node>> maze;
  std::pair<int, int> start, end;
  size_t row, col;

  bool FileExists(const char *file);
};

#endif //MAZESOLVER_MAZE_H
