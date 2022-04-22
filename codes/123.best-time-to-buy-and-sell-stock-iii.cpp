/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
    const int inf = ~0u>>1;
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size();
        int dp1 = 0, dp2 = 0, premin = inf, dp1max = -inf;
        for (int i = 0; i < n; i++) {
            dp2 = max(dp2, prices[i] + dp1max);
            dp1max = max(dp1max, dp1 - prices[i]);
            ans = max(ans, dp2);
            
            dp1 = max(dp1, prices[i] - premin);
            premin = min(premin, prices[i]);
            ans = max(ans, dp1);
        }
        return ans;
    }
};
// @lc code=end

