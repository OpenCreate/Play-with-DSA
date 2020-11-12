#pragma once

#include <sstream>
#include <string>

template <typename T>
class LinkedList {
 public:
  LinkedList() {
    dummyHead_ = new Node();
    size_ = 0;
  }

  int getSize() const { return size_; }

  bool isEmpty() const { return size_ == 0; }

  void addFirst(T e) { add(0, e); }

  void add(int index, T e) {
    if (index < 0 || index > size_)
      throw std::invalid_argument("Add failed. Illegal index.");

    Node *prev = dummyHead_;
    for (int i = 0; i < index; ++i) prev = prev->next;
    prev->next = new Node(e, prev->next);
    size_++;
  }

  void addLast(T e) { add(size_, e); }

  ~LinkedList() {
    Node *cur = dummyHead_;
    while (cur != nullptr) {
      Node *delNode = cur;
      cur = cur->next;
      delete delNode;
    }
  }

 private:
  struct Node {
    T e;
    Node *next;

    Node() : next(nullptr) {}

    Node(T e) : e(e), next(nullptr) {}

    Node(T e, Node *next) : e(e), next(next) {}

    std::string toString() const {
      std::stringstream ss;
      ss << e;
      return ss.str();
    }
  };

 private:
  Node *dummyHead_;
  int size_;
};