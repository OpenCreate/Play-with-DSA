#pragma once

#include <sstream>
#include <string>

template <typename T>
class LinkedList {
 public:
  LinkedList() : head_(nullptr), size_(0) {}

  int getSize() const { return size_; }

  bool isEmpty() const { return size_ == 0; }

  void addFirst(T e) {
    // Node *node = new Node(e);
    // node->next = head_;
    // head_ = node;
    head_ = new Node(e, head_);
    size_++;
  }

  void add(int index, T e) {
    if (index < 0 || index > size_)
      throw std::invalid_argument("Add failed. Illegal index.");

    if (index == 0)
      addFirst(e);
    else {
      Node *prev = head_;
      for (int i = 0; i < index - 1; ++i) prev = prev->next;

      Node *node = new Node(e);
      node->next = prev->next;
      prev->next = node;
      // prev->next = new Node(e, prev->next);
    }

    size_++;
  }

  void addLast(T e) { add(size_, e); }

  ~LinkedList(){
    Node *cur = head_;
    while(cur != nullptr){
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
  Node *head_;
  int size_;
};