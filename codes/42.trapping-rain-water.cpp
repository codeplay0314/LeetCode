/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int w = height.size(), h = 0;
        
        int larea = 0, rarea = 0, bar = 0;
        for (int i = 0; i < w; i++) {
            h = max(h, height[i]);
            larea += h;
            bar += height[i];
        }
        
        h = 0;
        for (int i = w - 1; i >= 0; i--) {
            h = max(h, height[i]);
            rarea += h;
        }
        
        return  (int)(-(long long)h * w - bar + larea + rarea);
    }
};
// @lc code=end

