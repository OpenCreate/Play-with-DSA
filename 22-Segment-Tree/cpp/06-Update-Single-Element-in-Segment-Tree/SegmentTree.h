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
    merger_ = merge;
    buildSegmentTree(0, 0, data_.size() - 1);
  }

  int getSize() const { return data_.size(); }

  T get(int index) {
    if (index < 0 || index >= data_.size())
      throw std::invalid_argument("Index is illegal.");
    return data_[index];
  }

  // 返回区间[queryL, queryR]的值
  T query(int queryL, int queryR) {
    if (queryL < 0 || queryL >= data_.size() || queryR < 0 ||
        queryR >= data_.size() || queryL > queryR)
      throw std::invalid_argument("Index is illegal.");
    return query(0, 0, data_.size() - 1, queryL, queryR);
  }

  // 将index位置的值，更新为e
  void set(int index, T e) {
    if (index < 0 || index >= data_.size())
      throw std::invalid_argument("Index is illegal");
    set(0, 0, data_.size() - 1, index, e);
  }

 private:
  // 在以treeIndex为根的线段树中更新index的值为e
  void set(int treeIndex, int l, int r, int index, T e) {
    if (l == r) {
      tree_[treeIndex] = e;
      return;
    }

    int mid = l + (r - l) / 2;

    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);

    if (index >= mid + 1)
      set(rightTreeIndex, mid + 1, r, index, e);
    else  // index < mid
      set(leftTreeIndex, l, mid, index, e);

    tree_[treeIndex] = merger_(tree_[leftTreeIndex], tree_[rightTreeIndex]);
  }

  // 在以treeIndex为根的线段树中[l...r]的范围里，搜索区间[queryL...queryR]的值
  T query(int treeIndex, int l, int r, int queryL, int queryR) {
    if (l == queryL && r == queryR) return tree_[treeIndex];
    int mid = l + (r - l) / 2;
    // treeIndex的节点分为[l...mid]和[mid+1...r]两部分
    int leftTreeIndex = leftChild(treeIndex);
    int rightTreeIndex = rightChild(treeIndex);
    if (queryL >= mid + 1)
      return query(rightTreeIndex, mid + 1, r, queryL, queryR);
    else if (queryR <= mid)
      return query(leftTreeIndex, l, mid, queryL, queryR);

    T leftResult = query(leftTreeIndex, l, mid, queryL, mid);
    T rightResult = query(rightTreeIndex, mid + 1, r, mid + 1, queryR);
    return merger_(leftResult, rightResult);
  }

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
    tree_[treeIndex] = merger_(tree_[leftTreeIndex], tree_[rightTreeIndex]);
  }

  // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
  int leftChild(int index) { return 2 * index + 1; }

  // 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
  int rightChild(int index) { return 2 * index + 2; }

 private:
  std::vector<T> data_;
  std::vector<T> tree_;
  std::function<T(T, T)> merger_;

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