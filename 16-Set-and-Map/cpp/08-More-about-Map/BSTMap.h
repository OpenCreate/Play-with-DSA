#pragma once

#include "Map.h"

template <typename K, typename V>
class BSTMap : public Map<K, V> {
 private:
  struct Node {
    K key;
    V value;
    Node *left;
    Node *right;
    Node(K key, V value)
        : key(key), value(value), left(nullptr), right(nullptr) {}
    Node(Node *node)
        : key(node->key),
          value(node->value),
          left(node->left),
          right(node->right) {}
  };

 public:
  BSTMap() : root_(nullptr), size_(0) {}

  int getSize() const override { return size_; }

  bool isEmpty() const override { return size_ == 0; }

  void add(K key, V value) override { root_ = add(root_, key, value); }

  bool contains(K key) const override { return getNode(root_, key) != nullptr; }

  V get(K key) const override {
    Node *node = getNode(root_, key);
    if (node != nullptr) return node->value;
    throw std::invalid_argument(key + "does't exist!");
  }

  void set(K key, V newValue) override {
    Node *node = getNode(root_, key);
    if (node == nullptr) throw std::invalid_argument(key + "does't exist!");
    node->value = newValue;
  }

  V remove(K key) override {
    Node *node = getNode(root_, key);
    if (node != nullptr) {
      root_ = remove(root_, key);
      return node->value;
    }
    throw std::invalid_argument(key + "does't exist!");
  }

 private:
  Node *getNode(Node *node, K key) const {
    if (node == nullptr) return nullptr;
    if (key == node->key)
      return node;
    else if (key < node->key)
      return getNode(node->left, key);
    else  // key > node->key
      return getNode(node->right, key);
  }
  //向以node为根的二分搜索树中添加元素(key, value)
  //返回插入新节点后二分搜索数的根
  Node *add(Node *node, K key, V value) {
    if (node == nullptr) {
      size_++;
      return new Node(key, value);
    }
    if (key < node->key) {
      node->left = add(node->left, key, value);
    } else if (key > node->key) {
      node->right = add(node->right, key, value);
    } else {
      node->value = value;
    }

    return node;
  }

  //返回以node为根的二分搜索树的最小值所在的节点
  Node *minimum(Node *node) const {
    if (node->left == nullptr) return node;
    return minimum(node->left);
  }

  Node *removeMin(Node *node) {
    //找到了最小值所在的节点
    if (node->left == nullptr) {
      Node *rightNode = node->right;
      // node->right = nullptr;
      delete node;
      size_--;
      return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
  }

  Node *remove(Node *node, K key) {
    if (node == nullptr) return nullptr;
    if (key < node->key) {
      node->left = remove(node->left, key);
      return node;
    } else if (key > node->key) {
      node->right = remove(node->right, key);
      return node;
    } else {  // k == node->key
      if (node->left == nullptr) {
        Node *rightNode = node->right;
        delete node;
        size_--;
        return rightNode;
      }

      if (node->right == nullptr) {
        Node *leftNode = node->left;
        delete node;
        size_--;
        return leftNode;
      }

      //左右子树都不为空
      // 1.选择左子树中的最大节点作为后继
      // 2.选择右子树中的最小节点作为后继
      //两者选其一即可,在此我选择第二种方案
      Node *successor = new Node(minimum(node->right));
      // size_++;
      successor->right = removeMin(node->right);
      successor->left = node->left;
      delete node;
      // size_--;
      return successor;
    }
  }

 private:
  Node *root_;
  int size_;
};