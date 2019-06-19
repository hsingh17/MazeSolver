#include "Maze.h"
#include <fstream>
#include <iterator>
#include <iostream>

Maze::Maze(char* file_path) {
  // Read in num rows and columns
  std::ifstream file(file_path);

  // Resize the maze accordingly
  file >> row >> col;
  maze.resize(row, std::vector<char>(col));

  // If row or col is not an int
  if (file.fail()) {
    std::cerr << "Invalid row/col!" << std::endl;
    exit(1);
  }

  // Read in the maze from file
  char c;
  bool is_start = false, is_finish = false;

  for (int i = 0; i < Row(); i++) {
    for (int j = 0; j < Col(); j++) {
       file >> c;
       if (c == 'S') {
         is_start = true;
         start = std::make_pair(i, j);
       } else if (c == 'F') {
         is_finish = true;
         end = std::make_pair(i, j);
       }
       maze[i][j] = c;
    }
  }

  // Error handling for no start or finish
  if (!is_start || !is_finish) {
    std::cerr << "No start/finish! Please give a start/finish" << std::endl;
    exit(1);
  }
}

const std::vector<std::vector<char>>& Maze::GetMaze() const {
  return maze;
}
const std::pair<int, int> Maze::Start() const {
  return start;
}
const std::pair<int, int> Maze::End() const {
  return end;
}

const size_t Maze::Col() const {
  return col;
}

const size_t Maze::Row() const {
  return row;
}

const std::vector<std::pair<int, int>> Maze::Adj(const std::pair<int, int>& v) const {
  // Get the spots adjacent to v.
  // In this implementation, diagonal paths are not allowed
  std::vector<std::pair<int, int>> adj;
  int north = v.first - 1, east = v.second + 1, south = v.first + 1, west = v.second - 1;

  // Check NESW directions to see if space can be moved onto
  if (north >= 0 && maze[north][v.second] != '+')
    adj.emplace_back(north, v.second);

  if (east < Col() && maze[v.first][east] != '+')
    adj.emplace_back(v.first, east);

  if (south < Row() && maze[south][v.second] != '+')
    adj.emplace_back(south, v.second);

  if (west >= 0 && maze[v.first][west] != '+')
    adj.emplace_back(v.first, west);

  return adj;
}

char& Maze::At(const std::pair<int, int>& v) {
  return maze[v.first][v.second];
}

void Maze::UpdateMaze(const char* new_file) {
  // Check if file already exists
  if (FileExists(new_file)) {
    std::cerr << "File: " << new_file <<
              " already exists. Please give a unique file name!" << std::endl;
    exit(1);
  }

  // Create solutions file
  std::ofstream solution(new_file);

  // Update the maze to show the final path
  for (int i = 0; i < Row(); i++) {
    for (int j = 0; j < Col(); j++)
      solution << At(std::make_pair(i, j));
    solution << '\n';
  }

  solution.close();
}

bool Maze::FileExists(const char *file) {
  std::ifstream ifile(file);
  return ifile.good();
}

