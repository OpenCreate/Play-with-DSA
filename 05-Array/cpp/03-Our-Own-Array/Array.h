#pragma once

class Array {
 public:
  Array() : data_(new int[10]), size_(0), capacity_(10) {}

  Array(int capacity)
      : data_(new int[capacity]), size_(0), capacity_(capacity) {}

  Array(const Array& arr) = delete;

  Array& operator=(const Array& rhs) = delete;

  int getSize() const { return size_; }

  int getCapacity() const { return capacity_; }

  bool isEmpty() const { return size_ == 0; }

  ~Array() {
    if (data_) delete[] data_;
  }

 private:
  int* data_;
  int size_;
  int capacity_;
};