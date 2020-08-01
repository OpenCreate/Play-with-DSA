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

  void addFirst(int e) { add(0, e); }

  void addLast(int e) { add(size_, e); }

  void add(int index, int e) {
    if (size_ == capacity_)
      throw std::invalid_argument("add failed. Array is full");
    if (index < 0 || index > size_)
      throw std::invalid_argument("add failed. Index is illegal");
    for (int i = size_ - 1; i > index; --i) data_[i + 1] = data_[i];
    data_[index] = e;
    size_++;
  }

  ~Array() {
    if (data_) delete[] data_;
  }

 private:
  int* data_;
  int size_;
  int capacity_;
};