#include <string.h>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "LinkedListMap.h"
#include "Map.h"

using namespace std;

std::string str_tolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return s;
}

void calcWords(string str, Map<string, int> &map) {
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
      if (map.contains(word))
        map.set(word, map.get(word) + 1);
      else
        map.add(word, 1);
      token = strtok(NULL, " ");
    }
  }

  cout << "Frequency of PRIDE : " << map.get("pride") << endl;

  cout << words.size() << endl;
  cout << map.getSize() << endl;
}

void test(string filename, Map<string, int> &map) {
  clock_t startTime = clock();
  calcWords(filename, map);
  clock_t endTime = clock();
  double time = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

  std::cout << "time :" << time << "s" << std::endl;
}

int main() {
  LinkedListMap<string, int> listMap;
  cout << "Pride and Prejudice:" << endl;
  test("pride-and-prejudice.txt", listMap);

  return 0;
}
