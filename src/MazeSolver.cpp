#include "MazeSolver.h"
#include <algorithm>


MazeSolver::MazeSolver(Maze& m) : m(m) {
  SolveMaze(m.Start());
  BuildPath(m(m.End().GetPrev().first, m.End().GetPrev().second));
}
void MazeSolver::SolveMaze(Node& start) {
  start.SetG(0);

  // Calculate h_cost of start. h_cost = f_cost since g_cost = 0
  start.SetH(abs(m.Start().GetX() - m.End().GetX()) + m.Start().GetY() - m.End().GetY());
  start.SetF(m.Start().GetH());
  open.push_back(start);

  while(!open.empty()) {
    std::sort(open.begin(), open.end());
    closed.push_back(open.front());
    Node& cur_node = open.front();
    open.pop_front();

    // Check if we have found the end
    if (cur_node == m.End())
      found_end = true;

    for (Node& copy : m.Adj(cur_node)) {
      Node& adj_node = m(copy.GetX(), copy.GetY());
      if (!InClosed(adj_node) && !InOpen(adj_node)) {
        open.push_back(adj_node);

        // Calculate cost from going from current node to start
        int g_cost_x = abs(adj_node.GetX() - m.Start().GetX());
        int g_cost_y = abs(adj_node.GetY() - m.Start().GetY());
        adj_node.SetG(g_cost_x + g_cost_y);

        // Calculate cost from going from current node to end
        int h_cost_x = abs(adj_node.GetX() - m.End().GetX());
        int h_cost_y = abs(adj_node.GetY() - m.End().GetY());
        adj_node.SetH(h_cost_x + h_cost_y);

        // F cost is the total cost
        int f_cost = adj_node.GetG() + adj_node.GetH();

        // If the current F cost is less than the node's current f cost
        // We must change it
        if (f_cost < adj_node.GetF()){
          adj_node.SetF(f_cost);
          adj_node.SetPrev(cur_node.GetX(), cur_node.GetY());
        }
      }
    }
  }
}

void MazeSolver::BuildPath(Node node) {
  do {
    m(node.GetX(), node.GetY()).SetPiece('@');
    node = m(node.GetPrev().first, node.GetPrev().second);
  } while (node.GetPrev() != std::make_pair(-1, -1));
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
