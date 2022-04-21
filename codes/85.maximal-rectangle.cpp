/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class LargestRectangle {
    stack<int> h, pos;
    void clear() {
        while (!h.empty()) h.pop(), pos.pop();
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int w = heights.size();
        vector<int> l(w), r(w);
        clear();
        for (int i = 0; i < w; i++) {
            while (!h.empty() && h.top() >= heights[i]) h.pop(), pos.pop();
            l[i] = h.empty() ? -1 : pos.top();
            h.push(heights[i]), pos.push(i);
        }
        clear();
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

class Solution {
    LargestRectangle LR;
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> histo(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) histo[0][j] = matrix[0][j] - '0';
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                histo[i][j] = (matrix[i][j] - '0') * (histo[i - 1][j] + (matrix[i][j] - '0'));
        int ans = 0;
        for (auto row : histo) {
            ans = max(ans, LR.largestRectangleArea(row));
        }
        return ans;
    }
};
// @lc code=end

