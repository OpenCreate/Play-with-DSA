#pragma once

#include <functional>
#include <iostream>
#include <limits>
#include <vector>
template <typename T>
class SegmentTree {
 public:
  SegmentTree(std::vector<T> &arr) : data_(arr) { tree_.resize(arr.size * 4); }

  int getSize() const { return data_.size(); }

  T get(int index) {
    if (index < 0 || index >= data_.length)
      throw std::invalid_argument("Index is illegal.");
    return data_[index];
  }

 private:
  // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
  int leftChild(int index) { return 2 * index + 1; }

  // 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
  int rightChild(int index) { return 2 * index + 2; }

 private:
  std::vector<T> data_;
  std::vector<T> tree_;
};