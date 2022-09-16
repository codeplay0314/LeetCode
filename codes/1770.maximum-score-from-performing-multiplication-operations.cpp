/*
 * @lc app=leetcode id=1770 lang=cpp
 *
 * [1770] Maximum Score from Performing Multiplication Operations
 */

// @lc code=start
class Solution {
    static const int maxm = 1e3;
    int dp[2 * maxm + 1][2 * maxm + 1];
public:
    int maximumScore(vector<int>& _nums, vector<int>& multipliers) {
        vector<int> nums;
        for (int i = 0; i < min(maxm, (int)_nums.size()); i++) nums.push_back(_nums[i]);
        for (int i = max(maxm, (int)_nums.size() - maxm); i < _nums.size(); i++) nums.push_back(_nums[i]);
        int n = nums.size();
        while (multipliers.size() < n) multipliers.push_back(0);
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                dp[i][i + l] = max(dp[i + 1][i + l] + nums[i] * multipliers[n - l], dp[i][i + l - 1] + nums[i + l - 1] * multipliers[n - l]);
            }
        }
        return dp[0][n];
    }
};
// @lc code=end

