#pragma once

#include <string>

template <typename T>
class LoopQueue {
 public:
  LoopQueue(int capacity) {
    data_ = new T[capacity + 1];
    capacity_ = capacity + 1;
    front_ = 0;
    tail_ = 0;
    size_ = 0;
  }

  LoopQueue() : LoopQueue(10) {}

  int getCapacity() const { return capacity_ - 1; }

  bool isEmpty() const { return front_ == tail_; }

  int getSize() const { return size_; }

  void enqueue(T e) {}

  T dequeue() { return T(); }

  T getFront() const { return T(); }

 private:
  T *data_;
  int capacity_;  //数组的长度
  int front_;
  int tail_;
  int size_;  //队列的大小
};