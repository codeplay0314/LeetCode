/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
    vector<int> q;
    int fr, sz, k;

    inline int incre(int x, int y) {
        return (x + y) % k;
    }
public:
    MyCircularQueue(int _k) {
        k = _k;
        q = vector<int>(k);
        fr = sz = 0;
    }
    
    bool enQueue(int value) {
        if (sz >= k) return false;
        q[incre(fr, sz++)] = value;
        return true;
    }
    
    bool deQueue() {
        if (sz <= 0) return false;
        fr = incre(fr, 1);
        sz--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[fr];
    }
    
    int Rear() {
        return isEmpty() ? - 1 : q[incre(fr, sz - 1)];
    }
    
    bool isEmpty() {
        return sz <= 0;
    }
    
    bool isFull() {
        return sz >= k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

