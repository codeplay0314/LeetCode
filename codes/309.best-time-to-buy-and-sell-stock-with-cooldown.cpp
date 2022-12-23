/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
    vector<int> dp;
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        dp = vector<int>(n + 1);
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], prices[i - 1] - prices[j - 1] + (j - 2 >= 0 ? dp[j - 2] : 0));
            }
        }
        return dp[n];
    }
};
// @lc code=end

