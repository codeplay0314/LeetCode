/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (nums[i] % 2 == 0)
                ans.push_back(nums[i]);
        for (int i = 0; i < n; i++)
            if (nums[i] % 2 == 1)
                ans.push_back(nums[i]);
        return ans;
    }
};
// @lc code=end
