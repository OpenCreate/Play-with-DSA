#pragma once

#include <sstream>
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

  bool isEmpty() const { return front_ == tail_; }

  int getSize() const { return size_; }

  int getCapacity() const { return capacity_ - 1; }

  void enqueue(T e) {
    if ((tail_ + 1) % capacity_ == front_) resize(getCapacity() * 2);
    data_[tail_] = e;
    tail_ = (tail_ + 1) % capacity_;
    size_++;
  }

  T dequeue() {
    if (isEmpty()) {
      throw std::invalid_argument("Cannot dequeue from an empty queue.");
    }
    T ret = data_[front_];
    front_ = (front_ + 1) % capacity_;
    size_--;
    if (size_ == getCapacity() / 4 && getCapacity() / 2 != 0)
      resize(getCapacity() / 2);
    return ret;
  }

  T getFront() {
    if (isEmpty()) throw std::invalid_argument("Queue is empty.");
    return data_[front_];
  }

  std::string toString() const {
    std::stringstream ss;
    ss << "LoopQueue size = " << size_ << ", capacity = " << getCapacity() << "\n";
    ss << "[";

    for (int i = front_; i != tail_; i = (i + 1) % capacity_) {
      ss << data_[i];
      if ((i + 1) % capacity_ != tail_) ss << ",";
    }
    ss << "]";
    return ss.str();
  }

 private:
  void resize(int newCapacity) {
    T* newData = new T[newCapacity + 1];
    for (int i = 0; i < size_; ++i) {
      newData[i] = data_[(front_ + i) % capacity_];
    }
    capacity_ = newCapacity + 1;
    delete[] data_;
    data_ = newData;
    front_ = 0;
    tail_ = size_;
  }

 private:
  T* data_;
  int capacity_;
  int front_;
  int tail_;
  int size_;
};