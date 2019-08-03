#include "MazeSolver.h"
#include <algorithm>


MazeSolver::MazeSolver(Maze& m) : m(m) {
  SolveMaze(m.Start());
  BuildPath();
}
void MazeSolver::SolveMaze(Node& start) {
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


  // Distance from start to itself is 0.
  // So g_cost is 0
  start.SetG(0);

  // Calculate h_cost of start. h_cost = f_cost since g_cost = 0
  start.SetH(abs(m.Start().GetX() - m.End().GetX()) + m.Start().GetY() - m.End().GetY());
  start.SetF(m.Start().GetH());
  open.push_back(start);

  while(!open.empty()) {
    std::sort(open.begin(), open.end());
    closed.push_back(open.front());
    Node cur_node = open.front();
    open.pop_front();
    for (Node copy_node : m.Adj(cur_node)) {
      Node& ref_node = m(copy_node.GetX(), copy_node.GetY());
      if (!InClosed(ref_node) && !InOpen(ref_node)) {
        open.push_back(ref_node);
        int g_cost_x = abs(ref_node.GetX() - m.Start().GetX());
        int g_cost_y = abs(ref_node.GetY() - m.Start().GetY());
        ref_node.SetG(g_cost_x + g_cost_y);

        int h_cost_x = abs(ref_node.GetX() - m.End().GetX());
        int h_cost_y = abs(ref_node.GetY() - m.End().GetY());
        ref_node.SetH(h_cost_x + h_cost_y);

        int f_cost = ref_node.GetG() + ref_node.GetH();

        if (f_cost < ref_node.GetF()){
          ref_node.SetF(f_cost);
          ref_node.SetPrev(cur_node.GetX(), cur_node.GetY());
        }
      }
    }
  }


}

void MazeSolver::BuildPath() {
//  auto cur_node = start;
//  while (!(cur_node == m.Start())) {
//    path.push_back(cur_node);
//    auto adj = m.Adj(cur_node);
//    std::sort(adj.begin(), adj.end());
//    for (auto& node : adj)
//      if (!InPath(node)) {
//        cur_node = node;
//        break;
//      }
//    m(cur_node.GetX(), cur_node.GetY()).SetPiece('@');
//  }
  Node& cur_node = m.End();
  while (cur_node.GetPrev() != std::make_pair(-1, -1)) {
    m(cur_node.GetX(), cur_node.GetY()).SetPiece('@');
    cur_node = m(cur_node.GetPrev().first, cur_node.GetPrev().second);
  }
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

//std::vector<Node> MazeSolver::GetPath() {
//  return path;
//}

bool MazeSolver::InPath(Node& node) {
  return std::find(path.begin(), path.end(), node) != path.end();
}
