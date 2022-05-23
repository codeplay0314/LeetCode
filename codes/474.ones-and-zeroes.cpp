/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= num; i++) {
            vector<int> sum(2, 0);
            for (char c : strs[i - 1]) {
                sum[c - '0']++;
            }
            for (int j = m; j >= sum[0]; j--) {
                for (int k = n; k >= sum[1]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - sum[0]][k - sum[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

