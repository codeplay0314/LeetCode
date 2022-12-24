/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Number of Lines To Write String
 */

// @lc code=start
class Solution {
    static const int mod = 1e9 + 7;
    vector<vector<int>> dp;
public:
    int numTilings(int n) {
        dp = vector<vector<int>>(n + 1, vector<int>(2, 0));
        dp[0][0] = dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1] * 2 % mod) % mod + dp[i - 2][0]) % mod;
            dp[i][1] = (dp[i - 1][1] + dp[i - 2][0]) % mod;
        }
        return dp[n][0];
    }
};
// @lc code=end

