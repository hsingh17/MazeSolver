#include "MazeSolver.h"
#include <algorithm>


MazeSolver::MazeSolver(Maze& m) : m(m) {
  SolveMaze(m.Start());
}
void MazeSolver::SolveMaze(Node start) {
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

  auto cur_node = m.Start();
  // Distance from start to itself is 0.
  // So g_cost is 0
  cur_node.SetG(0);

  // Calculate h_cost of start. h_cost = f_cost since g_cost = 0
  cur_node.SetH(abs(m.Start().GetX() - m.End().GetX()) + m.Start().GetY() - m.End().GetY());
  cur_node.SetF(m.Start().GetH());

  do {
    for (auto& node : m.Adj(cur_node)) {
      if (!InClosed(node) && !InOpen(node)) {
        open.push_back(node);
        int g_cost_x = abs(node.GetX() - m.Start().GetX());
        int g_cost_y = abs(node.GetY() - m.Start().GetY());
        node.SetG(g_cost_x + g_cost_y);

        int h_cost_x = abs(node.GetX() - m.End().GetX());
        int h_cost_y = abs(node.GetY() - m.End().GetY());
        node.SetH(h_cost_x + h_cost_y);

        int f_cost = node.GetG() + node.GetH();

        if (f_cost < node.GetF())
          node.SetF(f_cost);

      }
    }

    closed.push_back(cur_node);
    std::sort(open.begin(), open.end());
    cur_node = open.front();
    open.pop_front();
  } while (!open.empty());

}

bool MazeSolver::Possible() {
  // If we find the end then maze is solvable
  return found_end;
}

bool MazeSolver::InOpen(Node& node) {
  return std::find(open.begin(), open.end(), node) != open.end();
}

bool MazeSolver::InClosed(Node& node) {
  return std::find(closed.begin(), closed.end(), node) != closed.end();
}
