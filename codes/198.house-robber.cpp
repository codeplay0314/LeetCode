/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
    static const int maxn = 100;
    int dp[maxn + 1];
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};
// @lc code=end

