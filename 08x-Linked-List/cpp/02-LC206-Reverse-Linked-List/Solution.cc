// leetcode 206 翻转链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
  ListNode *reverseList(ListNode *head){
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *next = NULL;
    while(cur){
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
  }
};