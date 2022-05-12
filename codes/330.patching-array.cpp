/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long cur = 1;
        for (int i = 0, size = nums.size(); cur <= n; ) {
            if (i < size && nums[i] <= cur) cur += nums[i++];
            else cur += cur, ans++;
        }
        return ans;
    }
};
// @lc code=end

