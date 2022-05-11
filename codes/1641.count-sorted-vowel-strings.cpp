/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Minimum Degree of a Connected Trio in a Graph
 */

// @lc code=start
class Solution {
    const int C[6] = {1, 5, 10, 10, 5, 1};
public:
    int countVowelStrings(int n) {
        int dp[6][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 0; k < j; k++)
                    dp[i][j] += dp[i - 1][k];
        int ans = 0;
        for (int i = 1; i <= 5; i++)
            ans += dp[i][n] * C[i];
        return ans;
    }
};
// @lc code=end

