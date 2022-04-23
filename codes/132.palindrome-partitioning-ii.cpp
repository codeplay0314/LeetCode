/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
    const int inf = ~0u>>1;
public:
    int minCut(string s) {
        int n = s.size();
        bool isPldr[n][n + 1];
        memset(isPldr, false, sizeof(isPldr));
        for (int i = 0; i < n; i++) isPldr[i][i] = isPldr[i][i + 1] = true;
        for (int d = 2; d <= n; d++) {
            for (int l = 0; l < n && l + d <= n; l++) {
                isPldr[l][l + d] = (s[l] == s[l + d - 1]) && isPldr[l + 1][l + d - 1];
            }
        }
        
        int dp[n + 1];
        memset(dp, 127, sizeof(dp));
        dp[0] = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                if (isPldr[j][i]) dp[i] = min(dp[i], dp[j] + 1);
            }
        }

        return dp[n];
    }
};
// @lc code=end

