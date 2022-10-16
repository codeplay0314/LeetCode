/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution {
    static const int maxl = 300;
    static const int maxd = 10;
    int dp[maxd][maxl];
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int l = jobDifficulty.size();
        if (d > l) return -1;

        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < l; i++) dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]);

        for (int i = 1; i < d; i++) {
            for (int j = i; j < l; j++) {
                dp[i][j] = INT_MAX;
                for (int k = j - 1, curmax = jobDifficulty[j]; k >= i - 1; k--) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + curmax);
                    curmax = max(curmax, jobDifficulty[k]);
                }
            }
        }
        return dp[d - 1][l - 1];
    }
};
// @lc code=end

