/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
    static const int maxn = 100;
    int dp[maxn + 1] = {1};
public:
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] != '0') dp[1] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0') dp[i + 1] = dp[i];
            if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26) dp[i + 1] += dp[i - 1];
        }
        return dp[n];
    }
};
// @lc code=end

