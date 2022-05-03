/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
    priority_queue<int> lheap;
    priority_queue<int, vector<int>, greater<int>> rheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lheap.size() == rheap.size()) {
            if (!rheap.empty() && num > rheap.top()) {
                lheap.push(rheap.top());
                rheap.pop();
                rheap.push(num);
            } else {
                lheap.push(num);
            }
        } else {
            if (num < lheap.top()) {
                rheap.push(lheap.top());
                lheap.pop();
                lheap.push(num);
            } else {
                rheap.push(num);
            }
        }
    }
    
    double findMedian() {
        return lheap.size() == rheap.size() ? (lheap.top() + rheap.top()) / 2.0 : lheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

