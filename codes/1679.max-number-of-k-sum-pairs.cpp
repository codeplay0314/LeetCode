/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int l = 0, r = nums.size() - 1; l < r; l++) {
            while (r > l && nums[l] + nums[r] > k) r--;
            if (l < r && nums[l] + nums[r] == k) ans++, r--;
        }
        return ans;
    }
};
// @lc code=end

