/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *ehead = head ? head->next : nullptr;
        ListNode *t1 = head, *t2 = ehead;
        while (true) {
            if (t2 && t2->next) {
                t1 = t1->next = t2->next;
                t2 = t2->next = t1 ? t1->next : nullptr;
            } else {
                t1->next = ehead;
                break;
            }
        }
        return head;
    }
};
// @lc code=end

