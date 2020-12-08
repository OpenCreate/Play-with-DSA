#pragma once

template <typename T>
class Set {
 public:
  virtual void add(T e) = 0;
  virtual void remove(T e) = 0;
  virtual bool contains(T e) const = 0;
  virtual int getSize() const = 0;
  virtual bool isEmpty() const = 0;
};