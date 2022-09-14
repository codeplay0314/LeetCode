/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int _n;
    int remv(ListNode* node, ListNode* pre) {
        if (!node) return 0;
        int res = remv(node->next, node) + 1;
        if (res == _n) {
            pre->next = node->next;
        }
        return res;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nhead = new ListNode(0, head);
        _n = n;
        remv(head, nhead);
        return nhead->next;
    }
};
// @lc code=end

