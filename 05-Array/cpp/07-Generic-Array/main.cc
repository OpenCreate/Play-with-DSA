#include <iostream>
#include <sstream>
#include <string>
#include "Array.h"

class Student {
 public:
  Student() = default;

  Student(std::string name) : name_(name) {}

  bool operator==(const Student& rhs) { return name_ == rhs.name_; }

  friend std::stringstream& operator<<(std::stringstream& ss, const Student& stu);

 private:
  std::string name_;
};

std::stringstream& operator<<(std::stringstream& ss, const Student& stu) {
  ss << stu.name_.c_str();
  return ss;
}

int main() {
  Array<int> array(20);
  array.addFirst(-1);
  for (int i = 0; i < 10; ++i) {
    array.addLast(i + 1);
  }
  std::cout << array.toString() << std::endl;

  array.set(0, 99);
  array[1] = 100;
  std::cout << array.get(0) << " " << array.get(1) << std::endl;

  array.remove(2);
  std::cout << array.toString() << std::endl;

  array.removeFirst();
  std::cout << array.toString() << std::endl;

  Student s[] = {Student("Alice"), Student("Mike")};

  Array<Student> arr;
  arr.addLast(s[0]);
  arr.addLast(s[1]);
  arr.addLast(Student("Bob"));

  std::cout << arr.toString() << std::endl;

  return 0;
}
