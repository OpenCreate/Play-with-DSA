#pragma once

#include <sstream>
#include <string>

template <typename T>
class LinkedList {
 private:
  struct Node {
    T e;
    Node *next;

    Node() : next(nullptr) {}

    Node(T e) : e(e), next(nullptr) {}

    Node(T e, Node *next) : e(e), next(next) {}

    std::string toString() const {
      std::stringstream ss;
      ss << e;
      return ss.str();
    }
  };
};