/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
    static const int maxn = 500;
    int dp[maxn + 1][maxn + 1];
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return m + n - dp[m][n] * 2;
    }
};
// @lc code=end

