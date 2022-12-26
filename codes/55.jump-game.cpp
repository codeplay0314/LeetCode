/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), far = 0;
        for (int i = 0; i < n; i++) {
            if (far < i) return false;
            if (far < i + nums[i]) far = i + nums[i];
        }
        return far >= n - 1;
    }
};
// @lc code=end

