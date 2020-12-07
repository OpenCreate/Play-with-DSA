#pragma once

#include <iostream>
#include <stack>

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

  //非递归版
  void add2(T e) {
    if (root_ == nullptr) {
      root_ = new Node(e);
      size_++;
      return;
    }

    Node *p = root_;
    while (p != nullptr) {
      if (e < p->e) {
        if (p->left == nullptr) {
          p->left = new Node(e);
          size_++;
          return;
        }
        p = p->left;
      } else if (e > p->e) {
        if (p->right == nullptr) {
          p->right = new Node(e);
          size_++;
          return;
        }
        p = p->right;
      } else {
        return;
      }
    }
  }

  //看二分搜索树中是否包含元素e
  bool contains(T e) const { return contains(root_, e); }

  //前序遍历二分搜索树
  void preOrder() const { preOrder(root_); }

  //非递归前序遍历二分搜索树
  void preOrderNR() const {
    if (root_ == nullptr) return;
    std::stack<Node *> s;
    s.push(root_);
    while (!s.empty()) {
      Node *cur = s.top();
      s.pop();
      std::cout << cur->e << std::endl;
      if (cur->right) s.push(cur->right);
      if (cur->left) s.push(cur->left);
    }
  }

  //中序遍历二分搜索树
  void inOrder() const { inOrder(root_); }

  //后序遍历二分搜索树
  void postOrder() const { postOrder(root_); }

  ~BST() { destroy(root_); }

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

  //看以node为根的二分搜索书中是否包含元素e
  bool contains(Node *node, T e) const {
    if (node == nullptr) return false;

    if (e == node->e) return true;
    if (e < node->e)
      return contains(node->left, e);
    else if (e > node->e)
      return contains(node->right, e);
  }

  //前序遍历以node为根的二分搜索树
  void preOrder(Node *node) const {
    if (node == nullptr) return;
    std::cout << node->e << std::endl;
    preOrder(node->left);
    preOrder(node->right);
  }

  //中序遍历以node为根的二分搜索树
  void inOrder(Node *node) const {
    if (node == nullptr) return;
    inOrder(node->left);
    std::cout << node->e << std::endl;
    inOrder(node->right);
  }

  //后序遍历以node为根的二分搜索树
  void postOrder(Node *node) const {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->e << std::endl;
  }

  //销毁以node为根的二分搜索树
  void destroy(Node *node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    // std::cout << "destroy node:" << node->e << std::endl;
    delete node;
    node = nullptr;
  }
};