/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
    static const int num = 100;
    static const int maxn = 1e4;
    int dp[maxn + 1];
    int psqr[num + 2];
    void preprocess() {
        for (int i = 1; i <= num + 1; i++) {
            psqr[i] = i * i;
        }
    }
public:
    int numSquares(int n) {
        preprocess();
        dp[0] = 0;
        memset(dp + 1, 127, 4 * n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; psqr[j] <= i; j++) {
                dp[i] = min(dp[i], dp[i - psqr[j]] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

