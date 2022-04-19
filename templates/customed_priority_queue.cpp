// See: Problem 23. Merge k Sorted Lists
struct cmp {
    bool operator() (ListNode* u, ListNode* v) {
        return u->val > v->val;
    }
};
priority_queue<ListNode*, vector<ListNode*>, cmp> q;