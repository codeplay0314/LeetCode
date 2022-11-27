/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<long long, int> dp[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long dif = (long long)nums[j] - nums[i];
                int pre = dp[j][dif];
                ans += pre;
                dp[i][dif] += pre + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

