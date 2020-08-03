#pragma once

#include <sstream>
#include <string>

template <typename T>
class Array {
 public:
  Array() : data_(new T[10]), size_(0), capacity_(10) {}

  Array(int capacity) : data_(new T[capacity]), size_(0), capacity_(capacity) {}

  Array(const Array& arr) = delete;

  Array& operator=(const Array& rhs) = delete;

  int getSize() const { return size_; }

  int getCapacity() const { return capacity_; }

  bool isEmpty() const { return size_ == 0; }

  void addFirst(T e) { add(0, e); }

  void addLast(T e) { add(size_, e); }

  void add(int index, T e) {
    if (index < 0 || index > size_)
      throw std::invalid_argument("add failed. Index is illegal");
    if (size_ == capacity_) resize(size_ * 2);
    for (int i = size_ - 1; i > index; --i) data_[i + 1] = data_[i];
    data_[index] = e;
    size_++;
  }

  // for C++
  T& operator[](int index) {
    if (index < 0 || index >= size_)
      throw std::invalid_argument("failed. Index is illegal");
    return data_[index];
  }

  T get(int index) const {
    if (index < 0 || index >= size_)
      throw std::invalid_argument("Get failed. Index is illegal");
    return data_[index];
  }

  void set(int index, T e) {
    if (index < 0 || index >= size_)
      throw std::invalid_argument("Set failed. Index is illegal");
    data_[index] = e;
  }

  bool contains(T e) const {
    for (int i = 0; i < size_; ++i) {
      if (data_[i] == e) return true;
    }
    return false;
  }

  int find(T e) const {
    for (int i = 0; i < size_; ++i) {
      if (data_[i] == e) return i;
    }
    return -1;
  }

  //删除index位置元素，返回删除元T素
  T remove(int index) {
    if (index < 0 || index >= size_)
      throw std::invalid_argument("Set failed. Index is illegal");
    T ret = data_[index];
    for (int i = index + 1; i < size_; ++i) data_[i - 1] = data_[i];
    size_--;
    //防止复杂度震荡
    if (size_ == capacity_ / 4 && capacity_ / 2 != 0) resize(capacity_ / 2);
    return ret;
  }

  T removeFirst() { return remove(0); }

  T removeLast() { return remove(size_ - 1); }

  void removeElement(T e) {
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
  void resize(int newCapacity) {
    T* newData = new T[newCapacity];
    for (int i = 0; i < size_; ++i) newData[i] = data_[i];
    delete[] data_;//释放旧内存
    data_ = newData;
    capacity_ = newCapacity;
    
  }

  T* data_;
  int size_;
  int capacity_;
};