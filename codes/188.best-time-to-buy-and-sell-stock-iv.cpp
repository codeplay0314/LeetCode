/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
    const int maxp = 1000;
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(k + 1, 0);
        vector<int> ups(k + 1, -maxp - 1);
        for (int i = 1; i <= n; i++) {
            for (int j = k; j >= 0; j--) {
                ups[j] = max(ups[j], dp[j] - prices[i - 1]);
                if (j) dp[j] = max(dp[j], prices[i - 1] + ups[j - 1]);
            }
        }
        return dp[k];
    }
};
// @lc code=end

