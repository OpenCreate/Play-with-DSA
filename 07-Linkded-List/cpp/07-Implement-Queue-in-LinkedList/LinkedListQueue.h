#pragma once

#include <sstream>
#include <string>

template <typename T>
class LinkedListQueue {
 public:
  LinkedListQueue() : head_(nullptr), tail_(nullptr), size_(0) {}

  int getSize() const { return size_; }

  bool isEmpty() const { return size_ == 0; }

  void enqueue(T e) {
    if (head_ == nullptr) {
      head_ = new Node(e);
      tail_ = head_;
    } else {
      tail_->next = new Node(e);
      tail_ = tail_->next;
    }

    size_++;
  }

  T dequeue() {
    if (isEmpty()) {
      throw std::invalid_argument("Queue is empty.");
    }

    T ret = head_->e;
    Node *delNode = head_;
    delete delNode;
    head_ = head_->next;

    if (head_ == nullptr) tail_ = nullptr;
    size_--;
  }

  T getFront() const {
    if (isEmpty()) {
      throw std::invalid_argument("Queue is empty.");
    }
    return head_->e;
  }

 private:
  struct Node {
    Node() : next(nullptr) {}

    Node(T e, Node *next) : e(e), next(next) {}

    Node(T e) : Node(e, nullptr) {}

    std::string toString() const {
      std::stringstream ss;
      ss << e;
      return ss.str();
    }

    T e;
    Node *next;
  };

  Node *head_;
  Node *tail_;
  int size_;
};