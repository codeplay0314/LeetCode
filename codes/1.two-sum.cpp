/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int t = mp[target - nums[i]];
            if (t) {
                res.push_back(t - 1);
                res.push_back(i);
                return res;
            } else {
                mp[nums[i]] = i + 1;
            }
        }
        return res;
    }
};

// @lc code=end

