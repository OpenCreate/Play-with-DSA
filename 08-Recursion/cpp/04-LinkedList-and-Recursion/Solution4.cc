// 203. 移除链表元素
//删除链表中等于给定值 val 的所有节点。

#include <iostream>
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
  ListNode *removeElements(ListNode *head, int val) {
    if(head == NULL)
      return NULL;
    ListNode *res = removeElements(head->next, val);
    if(head->val == val)
      return res;
    head->next = res;
    return head;
  }
};

int main() {
  vector<int> vec{1, 2, 6, 3, 4, 5, 6};

  ListNode *head = new ListNode(vec);
  cout << *head << endl;
  cout << *(Solution().removeElements(head, 6)) << endl;;

  return 0;
}