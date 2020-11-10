#include <iostream>
#include "Stack.h"

class Student {
 public:
  Student() = default;

  Student(std::string name) : name_(name) {}

  bool operator==(const Student& rhs) { return name_ == rhs.name_; }

  friend std::stringstream& operator<<(std::stringstream& ss,
                                       const Student& stu);

  friend std::ostream& operator<<(std::ostream& os, const Student& stu);

 private:
  std::string name_;
};

std::stringstream& operator<<(std::stringstream& ss, const Student& stu) {
  ss << stu.name_.c_str();
  return ss;
}

std::ostream& operator<<(std::ostream& os, const Student& stu) {
  os << stu.name_;
  return os;
}

int main() {
  Stack<int> s1;
  std::cout << s1.isEmpty() << " " << s1.toString() << std::endl;
  for (int i = 0; i < 10; ++i) {
    s1.push(i);
  }

  std::cout << s1.toString() << std::endl;

  s1.pop();
  s1.pop();

  std::cout << s1.toString() << std::endl;

  Stack<Student> s2;
  s2.push(Student("Mike"));
  s2.push(Student("Alice"));
  s2.push(Student("Johns"));

  std::cout << s2.toString() << std::endl;

  s2.pop();

  std::cout << s2.toString() << std::endl;

  std::cout << s2.peek() << std::endl;

  return 0;
}
