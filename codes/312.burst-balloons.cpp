/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                dp[i][j] = 0;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], (k - 1 >= i ? dp[i][k - 1] : 0) + (k + 1 <= j ? dp[k + 1][j] : 0) + nums[k] * (i - 1 >= 0 ? nums[i - 1] : 1) * (j + 1 < n ? nums[j + 1] : 1));
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

