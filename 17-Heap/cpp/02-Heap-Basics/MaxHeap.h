#pragma once

#include "Array.h"

template <typename T>
class MaxHeap {
 public:
  MaxHeap(int capacity) : data_(capacity) {}

  MaxHeap() {}

  int getSize() const { return data_.getSize(); }

  bool isEmpty() const { return data_.isEmpty(); }

 private:
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
