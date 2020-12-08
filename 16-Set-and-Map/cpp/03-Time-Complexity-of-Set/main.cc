#include <string.h>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "BSTSet.h"
#include "LinkedListSet.h"
#include "Set.h"

using namespace std;

std::string str_tolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}

void calcWords(string str, Set<string> &set) {
  // ifstream fin("test.txt");
  ifstream file(str);
  string line;
  vector<string> words;
  // LinkedListSet<string> set;
  if (!file.is_open()) {
    cout << "open " << str << " failed\n";
    return;
  }
  while (getline(file, line)) {
    // 参考：https://www.zhihu.com/question/36642771/answer/865135551
    char *token = strtok(const_cast<char *>(line.data()), " ");
    while (token != NULL) {
      string word = str_tolower(token);
      words.push_back(word);
      set.add(word);
      token = strtok(NULL, " ");
    }
  }

  cout << words.size() << endl;
  cout << set.getSize() << endl;
}

void test(string filename, Set<string> &set) {
  clock_t startTime = clock();
  calcWords(filename, set);
  clock_t endTime = clock();
  double time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

  std::cout << "time :" << time << "s" << std::endl;
}

int main() {
  BSTSet<string> bst;
  cout << "Pride and Prejudice:" << endl;
  test("pride-and-prejudice.txt", bst);

  LinkedListSet<string> list;
  cout << "A tale of two cities:" << endl;
  test("a-tale-of-two-cities.txt", list);
  return 0;
}
