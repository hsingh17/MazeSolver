#include "Node.h"

Node::Node(int x, int y, char piece) : x(x), y(y), piece(piece) {}

Node::Node(const Node& rhs) : x(rhs.x), y(rhs.y), piece(rhs.piece), g_cost{rhs.g_cost}, h_cost(rhs.h_cost), f_cost(rhs.f_cost), prev(rhs.prev) {}

const int& Node::GetG() const {
  return g_cost;
}

const int& Node::GetH() const {
  return h_cost;
}

const int& Node::GetF() const {
  return f_cost;
}

const int& Node::GetX() const {
  return x;
}

const int& Node::GetY() const {
  return y;
}
const char& Node::GetPiece() const {
  return piece;
}

std::pair<int, int>& Node::GetPrev() {
  return prev;
}

void Node::SetG(int g_cost) {
  this->g_cost = g_cost;
}

void Node::SetH(int h_cost) {
  this->h_cost = h_cost;
}

void Node::SetF(int f_cost) {
  this->f_cost = f_cost;
}

void Node::SetPiece(char piece) {
  this->piece = piece;
}

void Node::SetPrev(int x, int y) {
  this->prev = std::make_pair(x, y);
}

bool Node::operator<(const Node& rhs) {
  return f_cost < rhs.f_cost;
}
bool Node::operator==(const Node& rhs) {
  return GetX() == rhs.GetX() && GetY() == rhs.GetY();
}
