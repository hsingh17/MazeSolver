#include "MazeSolver.h"
#include <algorithm>

MazeSolver::MazeSolver(Maze& m) : m(m) {
  SolveMaze(m.Start());
}
void MazeSolver::SolveMaze(std::pair<int, int> v) {
  // Base case
//  if (v == m.End()) {
//    found_end = true;
//    return;
//  }
//
//  visited.push_back(v);
//  // Loop through valid adjacent spots
//  for (const auto& w : m.Adj(v)) {
//    if (!Visited(w)) {
//      SolveMaze(w);
//      // 7 = Final path to end
//      if (found_end && w != m.End()) {
//        //m.At(w) = 7;
//        m.At(w) = '@';
//        return;
//      }
//    }
//  }
}

//bool MazeSolver::Visited(std::pair<int, int> v) {
//  return std::find(visited.begin(), visited.end(), v) != visited.end();
//}

bool MazeSolver::Possible() {
  // If we find the end then maze is solvable
  return found_end;
}
