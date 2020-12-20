#pragma once

#include <functional>
#include <iostream>
#include <limits>
#include <vector>
template <typename T>
class SegmentTree {
 public:
  SegmentTree(std::vector<T> &arr, std::function<T(T, T)> merge) : data_(arr) {
    tree_ = std::vector<T>(4 * arr.size(), std::numeric_limits<T>::min());
    merge_ = merge;
    buildSegmentTree(0, 0, data_.size() - 1);
  }

  int getSize() const { return data_.size(); }

  T get(int index) {
    if (index < 0 || index >= data_.length)
      throw std::invalid_argument("Index is illegal.");
    return data_[index];
  }

 private:
  //在treeIndex的位置创建表示[l..r]的线段树
  void buildSegmentTree(int treeIndex, int l, int r) {
    if (l == r) {
      tree_[treeIndex] = data_[l];
      return;
    }

    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);

    int mid = l + (r - l) / 2;
    buildSegmentTree(leftTreeIndex, l, mid);
    buildSegmentTree(rightTreeIndex, mid + 1, r);
    tree_[treeIndex] = merge_(tree_[leftTreeIndex], tree_[rightTreeIndex]);
  }
  // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
  int leftChild(int index) { return 2 * index + 1; }

  // 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
  int rightChild(int index) { return 2 * index + 2; }

 private:
  std::vector<T> data_;
  std::vector<T> tree_;
  std::function<T(T, T)> merge_;

  friend std::ostream &operator<<(std::ostream &os,
                                  const SegmentTree<T> &segTree) {
    os << "[";
    for (int i = 0; i < segTree.tree_.size(); i++) {
      if (segTree.tree_[i] > std::numeric_limits<T>::min()) {
        os << segTree.tree_[i];
      } else {
        os << "null";
      }

      if (i != segTree.tree_.size() - 1) {
        os << ", ";
      }
    }
    os << "]";
  }
};