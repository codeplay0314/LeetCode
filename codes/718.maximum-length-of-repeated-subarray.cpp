/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution {
    static const int maxn = 1e3;
    int dp[maxn + 1][maxn + 1];
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size(), m = nums2.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end

