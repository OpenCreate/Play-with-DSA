#pragma once

#include <sstream>
#include <string>
#include "LinkedList.h"

template <typename T>
class LinkedListStack {
 public:
  LinkedListStack()  {}


  int getSize() const { return container_.getSize(); }

  bool isEmpty() const { return container_.isEmpty(); }


  void push(const T& e) { container_.addFirst(e); }

  T pop() { return container_.removeFirst(); }

  T peek() { return container_.getFirst(); }

  std::string toString() const {
    std::stringstream ss;
    ss << "LinkedListStack: ";
    ss << "top[";
    int size = container_.getSize();
    for (int i = 0; i < size; ++i) {
      ss << container_.get(i);
      if (i != size - 1) ss << "->";
    }
    ss << "]";
    return ss.str();
  }

 private:
  LinkedList<T> container_;
};