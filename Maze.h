#ifndef MAZESOLVER_MAZE_H
#define MAZESOLVER_MAZE_H
#include "Node.h"
#include <vector>

class Maze {
 public:
  explicit Maze(char* file_path);

  const std::vector<std::vector<Node>>& GetMaze() const;
  std::vector<Node*> Adj(const Node& v) const;

  const size_t Row() const;
  const size_t Col() const;
  Node& Start();
  Node& End();
  //char& At(const std::pair<int, int>& v);

  void UpdateMaze(const char* new_file);

 private:
  std::vector<std::vector<Node>> maze;
  std::pair<int, int> start, end;
  size_t row, col;

  bool FileExists(const char *file);
};

#endif //MAZESOLVER_MAZE_H
