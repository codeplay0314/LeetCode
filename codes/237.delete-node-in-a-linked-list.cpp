/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    bool del(ListNode* node) {
        if (!node->next) return true;
        node->val = node->next->val;
        if (del(node->next)) {
            node->next = nullptr;
        }
        return false;
    }
public:
    void deleteNode(ListNode* node) {
        del(node);
    }
};
// @lc code=end

