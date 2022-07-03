/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
    static const int maxn = 1000;
    int f[maxn][2];
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            f[i][0] = f[i][1] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) f[i][0] = max(f[i][0], f[j][1] + 1);
                if (nums[j] > nums[i]) f[i][1] = max(f[i][1], f[j][0] + 1);
            }
            ans = max(ans, f[i][0]);
            ans = max(ans, f[i][1]);
        }
        return ans;
    }
};
// @lc code=end

