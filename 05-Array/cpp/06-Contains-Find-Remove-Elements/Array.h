#pragma once

#include <sstream>
#include <string>

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

  // for C++
  int& operator[](int index) {
    if (index < 0 || index >= size_)
      throw std::invalid_argument("failed. Index is illegal");
    return data_[index];
  }

  int get(int index) const {
    if (index < 0 || index >= size_)
      throw std::invalid_argument("Get failed. Index is illegal");
    return data_[index];
  }

  void set(int index, int e) {
    if (index < 0 || index >= size_)
      throw std::invalid_argument("Set failed. Index is illegal");
    data_[index] = e;
  }

  bool contains(int e) const {
    for (int i = 0; i < size_; ++i) {
      if (data_[i] == e) return true;
    }
    return false;
  }

  int find(int e) const {
    for (int i = 0; i < size_; ++i) {
      if (data_[i] == e) return i;
    }
    return -1;
  }

  //删除index位置元素，返回删除元素
  int remove(int index) {
    if (index < 0 || index >= size_)
      throw std::invalid_argument("Set failed. Index is illegal");
    int ret = data_[index];
    for (int i = index + 1; i < size_; ++i) data_[i - 1] = data_[i];
    size_--;
    return ret;
  }

  int removeFirst() { return remove(0); }

  int removeLast() { return remove(size_ - 1); }

  void removeElement(int e) {
    int index = find(e);
    if (index != -1) remove(index);
  }

  std::string toString() const {
    std::stringstream ss;
    ss << "Array size = " << size_ << ", capacity = " << capacity_ << "\n";
    ss << "[";
    for (int i = 0; i < size_; ++i) {
      ss << data_[i];
      if (i != size_ - 1) ss << ",";
    }
    ss << "]";
    return ss.str();
  }

  ~Array() {
    if (data_) delete[] data_;
  }

 private:
  int* data_;
  int size_;
  int capacity_;
};