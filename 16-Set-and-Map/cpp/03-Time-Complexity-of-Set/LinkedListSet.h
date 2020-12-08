#pragma once

#include "Set.h"
#include "LinkedList.h"

template <typename T>
class LinkedListSet : public Set<T> {
 public:
  LinkedListSet() {}

  void add(T e) override {
    if (!list.contains(e)) list.addFirst(e);
  }

  void remove(T e) override { list.removeElelment(e); }

  bool contains(T e) const override { return list.contains(e); }

  int getSize() const override { return list.getSize(); }

  bool isEmpty() const override { return list.isEmpty(); }

 private:
  LinkedList<T> list;
};