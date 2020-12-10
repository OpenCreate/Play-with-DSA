#pragma once

#include "Array.h"

template <typename T>
class MaxHeap {
 public:
  MaxHeap(int capacity) : data_(capacity) {}

  MaxHeap() {}

  MaxHeap(T arr[], int n) : data_(arr, n) {
    for (int i = parent(n - 1); i >= 0; i--) {
      siftDown(i);
    }
  }

  int getSize() const { return data_.getSize(); }

  bool isEmpty() const { return data_.isEmpty(); }

  void add(T e) {
    data_.addLast(e);
    siftUp(data_.getSize() - 1);
  }

  T findMax() {
    if (data_.getSize() == 0) throw std::invalid_argument("Heap is empty!");
    return data_[0];
  }
  T extractMax() {
    T ret = findMax();
    data_.swap(0, data_.getSize() - 1);
    data_.removeLast();
    siftDown(0);
    return ret;
  }

  T replace(T e) {
    T ret = findMax();
    data_.set(0, e);
    siftDown(0);
    return ret;
  }

 private:
  void siftUp(int k) {
    while (k > 0 && data_[parent(k)] < data_[k]) {
      std::swap(data_[parent(k)], data_[k]);
      k = parent(k);
    }
  }

  void siftDown(int k) {
    while (leftChild(k) < data_.getSize()) {
      int j = leftChild(k);
      if (j + 1 < data_.getSize() && data_[j] < data_[j + 1]) {
        j++;  // data_[j]中存储左右孩子中最大的值
      }
      if (data_[k] >= data_[j]) break;
      data_.swap(k, j);
      k = j;
    }
  }

  //返回二叉树的数组中，一个索引所表示的父亲节点的索引
  int parent(int index) const {
    if (index == 0) throw std::invalid_argument("index 0 does't have parent!");
    return (index - 1) / 2;
  }

  //返回二叉树中一个索引节点所表示左孩子节点的索引
  int leftChild(int index) const { return index * 2 + 1; }

  //返回二叉树中一个索引节点所表示右孩子节点的索引
  int rightChild(int index) const { return index * 2 + 2; }

 private:
  Array<T> data_;
};
