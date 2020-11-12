#pragma once

#include "Array.h"

template <typename T>
class ArrayQueue {
 public:
  ArrayQueue() {}

  int getSize() const { return container_.getSize(); }

  bool isEmpty() const { return container_.isEmpty(); }

  void enqueue(T e) { container_.addLast(e); }

  T dequeue() { container_.removeFirst(); }

  T getFront() const { return container_.getFirst(); }

 private:
  Array<T> container_;
};
