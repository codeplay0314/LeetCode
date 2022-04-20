/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
private:
    typedef pair<ListNode*, ListNode*> retV;
    retV reverse(ListNode* u, ListNode* pre, int k, int rest) {
        if (u == NULL) return make_pair((ListNode*)NULL, (ListNode*)NULL);
        
        retV ret = reverse(u->next, u, k, rest ? rest - 1 : k - 1);;
        if (rest > 0) {
            if (k == rest + 1) {
                if (ret.first == NULL) {
                    ret.second = u;
                }
                else {
                    u->next = ret.second;
                    ret.second = ret.first;
                }
            } else if (ret.first != NULL) {
                u->next = pre;
            }
        }
        else {
            u->next = pre;
            ret.first = u;
        }
        return ret;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        return reverse(head, NULL, k, k - 1).first;
    }
};
// @lc code=end

