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

  ~LinkedList() {
    Node *cur = dummyHead_;
    while (cur != nullptr) {
      Node *delNode = cur;
      cur = cur->next;
      delete delNode;
    }
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

  T get(int index) const {
    if (index < 0 || index >= size_) {
      throw std::invalid_argument("Get failed. Illegal index.");
    }
    Node *cur = dummyHead_->next;
    for (int i = 0; i < index; ++i) cur = cur->next;
    return cur->e;
  }

  T getFirst() const { return get(0); }

  T getLast() const { return get(size_ - 1); }

  void set(int index, T e) {
    if (index < 0 || index >= size_) {
      throw std::invalid_argument("Set failed. Illegal index.");
    }

    Node *cur = dummyHead_->next;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    cur->e = e;
  }

  bool contains(T e) {
    Node *cur = dummyHead_->next;
    while (cur != nullptr) {
      if (cur->e == e) return true;
      cur = cur->next;
    }
    return false;
  }

  T remove(int index) {
    if (index < 0 || index >= size_) {
      throw std::invalid_argument("Remove failed. Illegal index.");
    }
    Node *prev = dummyHead_;
    for (int i = 0; i < index; ++i) {
      prev = prev->next;
    }

    Node *delNode = prev->next;
    T ret = delNode->e;
    prev->next = delNode->next;
    delete delNode;
    size_--;
    return ret;
  }

  T removeFirst() { return remove(0); }

  T removeLast() { return remove(size_ - 1); }

  void removeElelment(T e) {
    Node *prev = dummyHead_;
    while (prev->next != nullptr) {
      if (prev->next->e == e) break;
      prev = prev->next;
    }

    if (prev->next != nullptr) {
      Node *delNode = prev->next;
      prev->next = delNode->next;
      delete delNode;
      size_--;
    }
  }

  std::string toString() const {
    std::stringstream ss;
    for (Node *cur = dummyHead_->next; cur != nullptr; cur = cur->next)
      ss << (*cur).toString() << "->";

    ss << "NULL";
    return ss.str();
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