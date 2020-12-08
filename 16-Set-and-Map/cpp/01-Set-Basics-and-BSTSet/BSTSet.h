#pragma once

#include "BST.h"
#include "Set.h"

template <typename T>
class BSTSet : public Set<T> {
 public:
  BSTSet() {}

  void add(T e) override { bst.add(e); }

  void remove(T e) override { bst.remove(e); }

  bool contains(T e) const override { return bst.contains(e); }

  int getSize() const override { return bst.getSize(); }

  bool isEmpty() const override { return bst.isEmpty(); }

 private:
  BST<T> bst;
};