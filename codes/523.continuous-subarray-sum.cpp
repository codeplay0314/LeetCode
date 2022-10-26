/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
    unordered_map<int, bool> exist;
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for (int i = 0, sum = 0, pre = 0, sz = nums.size(); i < sz; i++) {
            sum = ((long long)sum + nums[i]) % k;
            if (exist[sum]) return true;
            exist[pre] = true;
            pre = sum;
        }
        return false;
    }
};
// @lc code=end

