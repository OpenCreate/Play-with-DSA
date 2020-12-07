#pragma once

template <typename T>
class BST {
 private:
  struct Node {
    Node(T e) : e(e), left(nullptr), right(nullptr) {}

    T e;
    Node *left;
    Node *right;
  };

  Node *root_;
  int size_;

 public:
  BST() : root_(nullptr), size_(0) {}

  int getSize() const { return size_; }

  bool isEmpty() const { return size_ == 0; }

  void add(T e) {
    if (root_ == nullptr) {
      root_ = new Node(e);
      size_++;
      return;
    } else {
      add(root_, e);
    }
  }

 private:
  //向以node为根的二分搜索树中添加元素e
  void add(Node *node, T e) {
    if (e == node->e)
      return;
    else if (e < node->e && node->left == nullptr) {
      node->left = new Node(e);
      size_++;
      return;
    } else if (e > node->e && node->right == nullptr) {
      node->right = new Node(e);
      size_++;
      return;
    }

    if (e < node->e) {
      add(node->left, e);
    } else {
      add(node->right, e);
    }
  }
};