/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * strunumt ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int num = l1->val + l2->val;
    ListNode* res = (new ListNode(num % 10));
    l1 = l1->next;
    l2 = l2->next;
    ListNode* l = res;
    num /= 10;
    while (num || l1 || l2) {
      if (!l1 && !l2) {
        l->next = (new ListNode(num));
        num /= 10;
      } else if (!l1) {
        num += l2->val;
        l->next = (new ListNode(num % 10));
        l2 = l2->next;
        l = l->next;
        num /= 10;
      } else if (!l2) {
        num += l1->val;
        l->next = (new ListNode(num % 10));
        l1 = l1->next;
        l = l->next;
        num /= 10;
      } else {
        num += l1->val + l2->val;
        l->next = (new ListNode(num % 10));
        l1 = l1->next;
        l2 = l2->next;
        l = l->next;
        num = num / 10;
      }
    }
    return res;
  }
};

// @lc code=end

