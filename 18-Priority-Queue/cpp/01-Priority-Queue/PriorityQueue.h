#pragma once

#include "MaxHeap.h"

template <typename T>
class PriorityQueue {
 public:
  PriorityQueue() = default;

  int getSize() const { return maxHeap_.getSize(); }

  bool isEmpty() const { return maxHeap_.isEmpty(); }

  T getFront() { return maxHeap_.findMax(); }

  void enqueue(T e) { maxHeap_.add(e); }

  T dequeue() { return maxHeap_.extractMax(); }

 private:
  MaxHeap<T> maxHeap_;
};
