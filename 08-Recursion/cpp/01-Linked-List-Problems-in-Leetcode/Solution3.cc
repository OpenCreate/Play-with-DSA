// 203. 移除链表元素
//删除链表中等于给定值 val 的所有节点。

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode *prev = dummyHead;
    while (prev->next != NULL) {
      if (prev->next->val == val) {
        ListNode *delNode = prev->next;
        prev->next = delNode->next;
        delete delNode;
      } else
        prev = prev->next;
    }

    ListNode *ret = dummyHead->next;
    delete dummyHead;

    return ret;
  }
};