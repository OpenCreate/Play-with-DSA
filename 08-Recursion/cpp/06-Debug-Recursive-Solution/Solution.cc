// 203. 移除链表元素
//删除链表中等于给定值 val 的所有节点。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(const vector<int> &vec) {
    ListNode *head = this;
    head->val = vec[0];
    for (int i = 1; i < vec.size(); ++i) {
      head->next = new ListNode(vec[i]);
      head = head->next;
    }
  }

  friend ostream &operator<<(ostream &os, ListNode &list) {
    ListNode *cur = &list;
    while (cur) {
      os << cur->val << "->";
      cur = cur->next;
    }
    os << "NULL";

    return os;
  }
};

class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val, int depth) {
    string depthString = generateDepthString(depth);
    cout << depthString;
    cout << "Call remove " << val << " in " << *head << endl;
    if (head == NULL) {
      cout << depthString;
      cout << "Return " << *head << endl;
      return NULL;
    }

    ListNode *ret = removeElements(head->next, val, depth + 1);
    cout << depthString;
    cout << "After remove " << val << " in " << *ret << endl;
    if (head->val == val) {
      delete head;
    } else {
      head->next = ret;
      ret = head;
    }
    cout << depthString;
    cout << "Return:" << *ret << endl;

    return ret;
  }

  string generateDepthString(int depth) {
    string s;
    for (int i = 0; i < depth; i++) {
      s += "--";
    }

    return s;
  }
};

int main() {
  vector<int> vec{1, 2, 6, 3, 4, 5, 6};

  ListNode *head = new ListNode(vec);
  cout << *head << endl;
  cout << *(Solution().removeElements(head, 6, 0)) << endl;

  return 0;
}