#pragma once
#include <sstream>
#include <string>

template <typename T>
class LinkedListR {
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
  // 在链表的递归实现中，我们不使用虚拟头结点，也能无差异的处理位置0的问题:)
  Node *head_;
  int size_;

 public:
  LinkedListR() {
    head_ = nullptr;
    size_ = 0;
  }

  ~LinkedListR() {
    Node *cur = head_;
    while (cur != nullptr) {
      Node *delNode = cur;
      cur = cur->next;
      delete delNode;
    }
  }

  int getSize() const { return size_; }

  bool isEmpty() const { return size_ == 0; }

  std::string toString() const {
    std::stringstream ss;
    for (Node *cur = head_; cur != nullptr; cur = cur->next)
      ss << (*cur).toString() << "->";

    ss << "NULL";
    return ss.str();
  }

 public:
  void add(int index, T e) {
    if (index < 0 || index > size_)
      throw std::invalid_argument("Add failed. Illegal index.");
    head_ = add(head_, index, e);
    size_++;
  }

  void addLast(T e) { add(size_, e); }

  void addFirst(T e) { add(0, e); }

  T get(int index) const {
    if (index < 0 || index >= size_) {
      throw std::invalid_argument("Get failed. Illegal index.");
    }

    return get(head_, index);
  }

  T getFirst() const { return get(0); }

  T getLast() const { return get(size_ - 1); }

  void set(int index, T e) {
    if (index < 0 || index >= size_) {
      throw std::invalid_argument("Set failed. Illegal index.");
    }
    set(head_, index, e);
  }

  T remove(int index) {
    if (index < 0 || index >= size_) {
      throw std::invalid_argument("Remove failed. Illegal index.");
    }
    std::pair<Node *, T> ret = remove(head_, index);
    head_ = ret.first;
    size_--;
    return ret.second;
  }

  T removeFirst() { return remove(0); }

  T removeLast() { return remove(size_ - 1); }

  void removeElelment(T e) {
    head_ = removeElelment(head_, e);
    size_--;
  }

 private:
  // 在以node为头结点的链表的index位置插入元素e，递归算法
  Node *add(Node *node, int index, T e) {
    if (index == 0) return new Node(e, node);
    node->next = add(node->next, index - 1, e);
    return node;
  }

 private:
  //在以node为头结点的链表中获取index位置的元素，递归算法
  T get(Node *node, int index) {
    if (index == 0) {
      return node->e;
      return get(node->next, index - 1);
    }
  }

  //在以node为头结点的链表中设置index位置的元素，递归算法
  void set(Node *node, int index, T e) {
    if (index == 0) {
      node->e = e;
      return;
    }
    set(node->next, index - 1, e);
  }

  //在以node为头结点的链表中删除index位置的元素，递归算法
  std::pair<Node *, T> remove(Node *node, int index) {
    if (index == 0) {
      Node *ret = node->next;
      T retE = node->e;
      delete node;
      return std::pair<Node *, T>(ret, retE);
    }
    std::pair<Node*,T> ret = remove(node->next, index - 1);
    node->next = ret.first;
    ret.first = node;
    return ret; 
  }

  Node *removeElelment(Node *node, T e) {
    if (node->e == e) {
      Node *ret = node->next;
      delete node;
      return ret;
    }

    node->next = removeElelment(node->next, e);
    return node;
  }
};