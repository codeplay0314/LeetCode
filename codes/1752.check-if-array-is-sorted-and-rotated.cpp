/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int num = nums[0] < nums[n - 1];
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) num++;
        }
        return num <= 1;
    }
};
// @lc code=end

