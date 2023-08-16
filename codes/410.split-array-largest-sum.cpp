/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
    int n;
public:
    int splitArray(vector<int>& nums, int k) {
        n = nums.size();

        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                for (int t = 0; t < i; t++) {
                    dp[i][j] = min(dp[i][j], max(dp[t][j - 1], sum[i] - sum[t]));
                }
            }
        }

        return dp[n][k];
    }
};
// @lc code=end

