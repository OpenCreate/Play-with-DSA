#pragma once

#include <sstream>
#include <string>
#include "Array.h"
template <typename T>
class Queue {
 public:
  Queue() : container_(10) {}

  Queue(int capacity) : container_(capacity) {}

  int getSize() const { return container_.getSize(); }

  bool isEmpty() const { return container_.isEmpty(); }

  int getCapacity() const { return container_.getCapacity(); }

  void enqueue(const T& e) { container_.addLast(e); }

  T dequeue() { return container_.removeFirst(); }

  T getFront() { return container_.getFirst(); }

  std::string toString() const {
    std::stringstream ss;
    ss << "Queue: ";
    ss << "front [";
    int size = container_.getSize();
    for (int i = 0; i < size; ++i) {
      ss << container_.get(i);
      if (i != size - 1) ss << ",";
    }
    ss << "] tail";
    return ss.str();
  }

 private:
  Array<T> container_;
};