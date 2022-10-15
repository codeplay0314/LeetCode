/*
 * @lc app=leetcode id=1531 lang=cpp
 *
 * [1531] String Compression II
 */

// @lc code=start
class Solution {
    static const int maxn = 100;
    int dp[maxn + 1][maxn + 1];
    inline int getdigit(int x) {
        if (x < 2) return 0;
        if (x < 10) return 1;
        if (x < 100) return 2;
        return 0;
    }
    inline bool isbp(int x) {
        return x == 1 || x == 2 || x == 10 || x == 100;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int len = s.length();
        s += "*";
        for (int i = len - 1, tmp; i >= 0; i--) {
            for (int j = k; j > 0; j--) {
                dp[i][j] = dp[i + 1][j - 1];
                for (int t = i + 1, cnt = 0; t <= len && cnt <= j; t++) {
                    dp[i][j] = min(dp[i][j], 1 + getdigit(t - i - cnt) + dp[t][j - cnt]);
                    if (s[i] != s[t]) cnt++;
                }
            }
            tmp = s[i] == s[i + 1] ? tmp + 1 : 1;
            dp[i][0] = dp[i + 1][0] + isbp(tmp);
        }
        return dp[0][k];
    }
};
// @lc code=end

