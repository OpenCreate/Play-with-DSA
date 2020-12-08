// https://leetcode-cn.com/problems/unique-morse-code-words/

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    string codes[] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                      "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                      "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                      "...-", ".--",  "-..-", "-.--", "--.."};
    set<string> s;
    for (auto word : words) {
      string res;
      for (int i = 0; i < word.size(); ++i) {
        res += codes[word[i] - 'a'];
      }
      s.insert(res);
      // res.clear();
    }

    return s.size();
  }
};