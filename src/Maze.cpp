#include "Maze.h"
#include <fstream>
#include <iterator>
#include <iostream>

Maze::Maze(char* file_path) {
  // Read in num rows and columns
  std::ifstream file(file_path);

  // Resize the maze accordingly
  file >> row >> col;
  maze.resize(row, std::vector<Node>(col));

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
       Node node(i, j, c);
       if (c == 'S') {
         is_start = true;
         start = std::make_pair(i ,j);
       } else if (c == 'F') {
         is_finish = true;
         end = std::make_pair(i, j);
       }
      maze[i][j] = node;
    }
  }

  // Error handling for no start or finish
  if (!is_start || !is_finish) {
    std::cerr << "No start/finish! Please give a start/finish" << std::endl;
    exit(1);
  }

  file.close();
}

const std::vector<std::vector<Node>>& Maze::GetMaze() const {
  return maze;
}
Node& Maze::Start() {
  return maze[start.first][start.second];
}
Node& Maze::End() {
  return maze[end.first][end.second];
}

const int Maze::Col() const {
  return col;
}

const int Maze::Row() const {
  return row;
}

std::vector<Node> Maze::Adj(Node& v) {
  // Get the spots adjacent to v.
  // In this implementation, diagonal paths are not allowed
  std::vector<Node> adj;

  int north = v.GetX() - 1, east = v.GetY() + 1, south = v.GetX() + 1, west = v.GetY() - 1;

  // Check NESW directions to see if space can be moved onto
  if (north >= 0 && maze[north][v.GetY()].GetPiece() != '+')
    adj.push_back(maze[north][v.GetY()]);


  if (east < Col() && maze[v.GetX()][east].GetPiece() != '+')
    adj.push_back(maze[v.GetX()][east]);

  if (south < Row() && maze[south][v.GetY()].GetPiece() != '+')
    adj.push_back(maze[south][v.GetY()]);

  if (west >= 0 && maze[v.GetX()][west].GetPiece() != '+')
    adj.push_back(maze[v.GetX()][west]);

  return adj;
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
      solution << maze[i][j].GetPiece();
    solution << '\n';
  }

  solution.close();
}

bool Maze::FileExists(const char* file) {
  std::ifstream ifile(file);
  return ifile.good();
}

Node& Maze::operator()(int x, int y) {
  return maze[x][y];
}

