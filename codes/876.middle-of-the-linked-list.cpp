/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* del(ListNode* node, int& p) {
        if (!node) {
            p /= 2;
            return nullptr;
        }        
        ListNode* res = del(node->next, ++p);
        return !--p ? node : res;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int p = 1;
        return del(head, p);
    }
};
// @lc code=end

