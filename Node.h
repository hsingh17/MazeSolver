#ifndef MAZESOLVER__NODE_H_
#define MAZESOLVER__NODE_H_

#include <climits>
class Node {
 public:
  Node() = default;
  explicit Node(int x, int y, char piece);

  const char& GetPiece() const;
  const int& GetX() const;
  const int& GetY() const;
  const int& GetG() const;
  const int& GetH() const;
  const int& GetF() const;

  void SetG(int g_cost);
  void SetH(int h_cost);
  void SetF(int f_cost);
  void SetPiece(char piece);


  bool operator<(const Node& rhs);
  bool operator==(const Node& rhs);

 private:
  int x, y, g_cost = INT_MAX, h_cost = INT_MAX, f_cost = INT_MAX;
  char piece;
};

#endif //MAZESOLVER__NODE_H_
