/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tailA = headA, *tailB = headB;
        int lenA = 1, lenB = 1;
        while (tailA->next) tailA = tailA->next, lenA++;
        while (tailB->next) tailB = tailB->next, lenB++;
        if (tailA != tailB) return NULL;
        while (lenA > lenB) headA = headA->next, lenA--;
        while (lenB > lenA) headB = headB->next, lenA--;
        while (headA != headB) headA = headA->next, headB = headB->next;
        return headA;
    }
};
// @lc code=end

