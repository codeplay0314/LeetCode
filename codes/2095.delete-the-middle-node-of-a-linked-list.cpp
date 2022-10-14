/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    int len = 0;
    int del(ListNode* node) {
        if (!node) return 0;
        len++;
        int num = del(node->next);
        if (num == len / 2) {
            node->next = node->next->next;
        }
        return num + 1;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* nhead = new ListNode(0, head);
        del(nhead);
        return nhead->next;
    }
};
// @lc code=end

