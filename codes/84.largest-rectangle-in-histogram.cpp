/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
    stack<int> h, pos;
public:
    int largestRectangleArea(vector<int>& heights) {
        int w = heights.size();
        vector<int> l(w), r(w);
        for (int i = 0; i < w; i++) {
            while (!h.empty() && h.top() >= heights[i]) h.pop(), pos.pop();
            l[i] = h.empty() ? -1 : pos.top();
            h.push(heights[i]), pos.push(i);
        }
        while (!h.empty()) h.pop(), pos.pop();
        for (int i = w - 1; i >= 0; i--) {
            while (!h.empty() && h.top() >= heights[i]) h.pop(), pos.pop();
            r[i] = h.empty() ? w : pos.top();
            h.push(heights[i]), pos.push(i);
        }
        int ans = 0;
        for (int i = 0; i < w; i++) ans = max(ans, (r[i] - l[i] - 1) * heights[i]);
        return ans;
    }
};
// @lc code=end

