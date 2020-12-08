#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "BSTSet.h"

using namespace std;

std::string str_tolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}

void calcWords(string str) {
  // ifstream fin("test.txt");
  ifstream file(str);
  string line;
  vector<string> words;
  BSTSet<string> set;
  if (!file.is_open()) {
    cout << "open " << str << " failed\n";
    return;
  }

  while (getline(file, line)) {
    // 参考：https://www.zhihu.com/question/36642771/answer/865135551
    char* token = strtok(const_cast<char*>(line.data()), " ");
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

int main() {
  cout << "Pride and Prejudice:" << endl;
  calcWords("pride-and-prejudice.txt");

  cout << "A tale of two cities:" << endl;
  calcWords("a-tale-of-two-cities.txt");

  return 0;
}
