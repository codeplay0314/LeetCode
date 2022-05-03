/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> lmax(nums);
        vector<int> rmin(nums);
        for (int i = 1; i < n; i++)
            lmax[i] = max(lmax[i - 1], lmax[i]);
        for (int i = n - 2; i >= 0; i--)
            rmin[i] = min(rmin[i], rmin[i + 1]);
        int l = 0, r = n - 1;
        while (l < n && nums[l] <= rmin[l]) l++;
        while (r >= 0 && nums[r] >= lmax[r]) r--;
        return l <= r ? r - l + 1 : 0;
    }
};
// @lc code=end

