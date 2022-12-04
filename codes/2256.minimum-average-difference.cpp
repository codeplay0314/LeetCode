/*
 * @lc app=leetcode id=2256 lang=cpp
 *
 * [2256] Minimum Average Difference
 */

// @lc code=start
class Solution {
    static const int maxn = 1e5;
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long tot = 0;
        for (int num : nums) tot += num;

        int ans = n - 1;
        int res = tot / n;
        long long pref = 0;
        for (int i = 1; i < n; i++) {
            pref += nums[i - 1];
            int cur = abs(pref / i - (tot - pref) / (n - i));
            if (cur < res || (cur == res && ans > i - 1)) {
                ans = i - 1;
                res = abs(pref / i - (tot - pref) / (n - i));
            }
        }
        return ans;
    }
};
// @lc code=end

