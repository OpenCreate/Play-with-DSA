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

  void add(T e) { root_ = add(root_, e); }

 private:
  //向以node为根的二分搜索树中添加元素e
  //返回插入新节点后二分搜索数的根
  Node *add(Node *node, T e) {
    if (node == nullptr) {
      size_++;
      return new Node(e);
    }
    if (e < node->e) {
      node->left = add(node->left, e);
    } else if (e > node->e) {
      node->right = add(node->right, e);
    }

    return node;
  }
};