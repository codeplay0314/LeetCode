/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        for (int i = 1, mincur[2] = {nums[0], INT_MAX}; i < nums.size(); i++) {
            if (nums[i] > mincur[1]) return true;
            if (nums[i] > mincur[0] && mincur[1] > nums[i]) mincur[1] = nums[i];
            if (mincur[0] > nums[i]) mincur[0] = nums[i];
        }
        return false;
    }
};
// @lc code=end

