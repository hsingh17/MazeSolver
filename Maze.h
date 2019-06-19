#ifndef MAZESOLVER_MAZE_H
#define MAZESOLVER_MAZE_H
#include <vector>

class Maze {
 public:
  explicit Maze(char* file_path);

  const std::vector<std::vector<char>>& GetMaze() const;
  const std::vector<std::pair<int, int>> Adj(const std::pair<int, int>& v) const;

  const size_t Row() const;
  const size_t Col() const;
  const std::pair<int, int> Start() const;
  const std::pair<int, int> End() const;
  char& At(const std::pair<int, int>& v);

  void UpdateMaze(const char* new_file);

 private:
  std::vector<std::vector<char>> maze;
  std::pair<int, int> start, end;
  size_t row, col;

  bool FileExists(const char *file);
};

#endif //MAZESOLVER_MAZE_H
