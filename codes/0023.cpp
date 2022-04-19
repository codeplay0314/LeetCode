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
    struct cmp {
        bool operator() (ListNode* u, ListNode* v) {
            return u->val > v->val;
        }
    };
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *st = new ListNode(), *cur = st;
        
        for (auto list : lists) {
            if (list != NULL) q.push(list);
        }        
        while (!q.empty()) {
            ListNode* nxt = q.top();
            q.pop();
            cur->next = nxt;
            cur = nxt;
            nxt = nxt->next;
            if (nxt != NULL) q.push(nxt);
        }
        
        return st->next;
    }
};