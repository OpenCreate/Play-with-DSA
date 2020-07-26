#include <iostream>
#include <string>
#include "LinearSearch.h"

using namespace std;

class Student {
 public:
  Student(string name) : name_(name) {}

  bool operator==(const Student& rhs) { return name_ == rhs.name_; }

 private:
  string name_;
};

int main() {
  int data[] = {22, 33, 15, 8, 79, 12, 90, 66, 5};

  int res = LinearSearch::search(data, sizeof(data) / sizeof(int), 15);
  cout << res << endl;

  int res2 = LinearSearch::search(data, sizeof(data) / sizeof(int), 1024);
  cout << res2 << endl;

  Student data2[] = {Student("Bobo"), Student("Alice"), Student("Mike"),
                     Student("David")};

  int res3 = LinearSearch::search(data2, sizeof(data2) / sizeof(Student),
                                  Student("Bobo"));
  cout << res3 << endl;

  int res4 = LinearSearch::search(data2, sizeof(data2) / sizeof(Student),
                                  Student("Trump"));
  cout << res4 << endl;

  return 0;
}
