/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
    const int mod = 1e9 + 7;
    int dp[31][1001] = {1};
public:
    int numRollsToTarget(int n, int k, int target) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1, cur = 0; j <= target; j++) {
                if (j - k - 1 >= 0) cur = (cur - dp[i - 1][j - k - 1] + mod) % mod;
                cur = (cur + dp[i - 1][j - 1]) % mod;
                dp[i][j] = cur;
            }
        }
        return dp[n][target];
    }
};
// @lc code=end

