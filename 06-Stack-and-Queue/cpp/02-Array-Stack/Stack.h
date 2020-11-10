#pragma once

#include <sstream>
#include <string>
#include "Array.h"
template <typename T>
class Stack {
 public:
  Stack() : container_(10) {}

  Stack(int capacity) : container_(capacity) {}

  int getSize() const { return container_.getSize(); }

  bool isEmpty() const { return container_.isEmpty(); }

  int getCapacity() const { return container_.getCapacity(); }

  void push(const T& e) { container_.addLast(e); }

  T pop() { return container_.removeLast(); }

  T peek() { return container_.getLast(); }

  std::string toString() const {
    std::stringstream ss;
    ss << "Stack: ";
    ss << "[";
    int size = container_.getSize();
    for (int i = 0; i < size; ++i) {
      ss << container_.get(i);
      if (i != size - 1) ss << ",";
    }
    ss << "] top";
    return ss.str();
  }

 private:
  Array<T> container_;
};