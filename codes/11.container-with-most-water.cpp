/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int width = height.size() - 1;
        int l = 0, r = width;
        int ans = 0;
        while (l < r) {
            ans = max(ans, width * min(height[l], height[r]));
            if (height[l] < height[r]) l++;
            else r--;
            width--;
        }
        return ans;
    }
};
// @lc code=end

