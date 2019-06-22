#ifndef MAZESOLVER__NODE_H_
#define MAZESOLVER__NODE_H_
#include <climits>
#include <memory>

class Node {
 public:
  Node() = default;
  explicit Node(int x, int y, char piece);
  Node(const Node& rhs);

  const char& GetPiece() const;
  const int& GetX() const;
  const int& GetY() const;
  const int& GetG() const;
  const int& GetH() const;
  const int& GetF() const;
  std::pair<int, int>& GetPrev();

  void SetG(int g_cost);
  void SetH(int h_cost);
  void SetF(int f_cost);
  void SetPiece(char piece);
  void SetPrev(int x, int y);

  bool operator<(const Node& rhs);
  bool operator==(const Node& rhs);

 private:
  int x, y, g_cost = INT_MAX, h_cost = INT_MAX, f_cost = INT_MAX;
  std::pair<int, int> prev = {-1, -1};
  char piece;
};

#endif //MAZESOLVER__NODE_H_
