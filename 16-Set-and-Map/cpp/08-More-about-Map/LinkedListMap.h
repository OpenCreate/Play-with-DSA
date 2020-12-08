#pragma once

#include <exception>
#include "Map.h"
template <typename K, typename V>
class LinkedListMap : public Map<K, V> {
 private:
  struct Node {
    K key;
    V value;
    Node *next;
    Node(K key, V value, Node *next) : key(key), value(value), next(next) {}
    Node(K key) : Node(key, value(), nullptr) {}
    Node() :next(nullptr){}
  };

 public:
  LinkedListMap() {
    dummyHead_ = new Node();
    size_ = 0;
  }

  int getSize() const override { return size_; }

  bool isEmpty() const override { return size_ == 0; }

  bool contains(K key) const override { return getNode(key) != nullptr; }

  V get(K key) const override {
    Node *node = getNode(key);
    // return node == nullptr ? nullptr:node->value;
    if (node != nullptr) return node->value;
    throw std::invalid_argument(key + "does't exist!");
  }

  void add(K key, V value) override {
    Node *node = getNode(key);
    if (node == nullptr) {
      dummyHead_->next = new Node(key, value, dummyHead_->next);
      size_++;
    } else {
      node->value = value;
    }
  }

  void set(K key, V newValue) override {
    Node *node = getNode(key);
    if (node == nullptr) {
      throw std::invalid_argument(key + "does't exist!");
    }
    node->value = newValue;
  }

  V remove(K key) override {
    Node *prev = dummyHead_;
    while (prev->next != nullptr) {
      if (prev->next->key == key) break;
      prev = prev->next;
    }

    if (prev->next != nullptr) {
      Node *delNode = prev->next;
      prev->next = delNode->next;
      V value = delNode->value;
      delete delNode;
      size_--;
      return value;
    }
    throw std::invalid_argument(key + "does't exist!");
  }

 private:
  Node *getNode(K key) const {
    Node *cur = dummyHead_->next;
    while (cur) {
      if (cur->key == key) return cur;
      cur = cur->next;
    }
    return nullptr;
  }

 private:
  Node *dummyHead_;
  int size_;
};