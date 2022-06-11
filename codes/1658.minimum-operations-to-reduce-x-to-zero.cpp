/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = n + 1;
        int l = 0, lsum = 0;
        int r = n, rsum = 0;
        while (l < n && lsum < x) lsum += nums[l++];
        if (lsum == x) ans = l;
        while (l--) {
            lsum -= nums[l];
            while (r > l && lsum + rsum < x) rsum += nums[--r];
            if (lsum + rsum == x) ans = min(ans, l + n - r); 
        }
        return ans > n ? -1 : ans;
    }
};
// @lc code=end

