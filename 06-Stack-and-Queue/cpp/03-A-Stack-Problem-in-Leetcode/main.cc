#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> s1;
    for (int i = 0; i < s.length(); ++i) {
      char c = s[i];
      if (c == '(' || c == '[' || c == '{')
        s1.push(c);
      else {
        if (s1.empty()) return false;
        char topChar = s1.top();
        s1.pop();
        if (c == ')' && topChar != '(') return false;
        if (c == ']' && topChar != '[') return false;
        if (c == '}' && topChar != '{') return false;
      }
    }

    return s1.empty();
  }
};

int main() {
  cout << Solution().isValid("()[]{}") << endl;
  cout << Solution().isValid("([)]") << endl;
  return 0;
}
