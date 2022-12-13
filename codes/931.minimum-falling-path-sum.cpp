/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int dp[n][n];
        for (int i = 0; i < n; i++) dp[0][i] = matrix[0][i];
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                if (j + 1 < n) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                dp[i][j] += matrix[i][j];
            }
        int ans = dp[n - 1][0];
        for (int i = 1; i < n; i++) ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};
// @lc code=end

