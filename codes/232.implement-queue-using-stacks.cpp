/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
    stack<int> st[2];
    void maintain() {
        while (!st[0].empty()) {
            st[1].push(st[0].top());
            st[0].pop();
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st[0].push(x);
    }
    
    int pop() {
        if (st[1].empty()) maintain();
        int res = st[1].top();
        st[1].pop();
        return res;
    }
    
    int peek() {
        if (st[1].empty()) maintain();
        return st[1].top();
    }
    
    bool empty() {
        maintain();
        return st[1].empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

