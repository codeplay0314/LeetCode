/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap(m, n);
        vector<vector<int>> dp(m, vector<int>(m + n - 1, 0));
        dp[0] = vector<int>(m + n - 1, 1);
        for (int i = 1; i < m; i++) {
            for (int j = i; j < m + n - 1; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
            }
        }
        return dp[m - 1][m + n - 2];
    }
};
// @lc code=end

