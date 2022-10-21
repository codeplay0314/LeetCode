/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
    unordered_map<int, int> mp;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int lim = min((int)nums.size(), k + 1);
        for (int i = 0; i < lim; i++) {
            if (mp[nums[i]]) return true;
            mp[nums[i]]++;
        }
        for (int i = lim, sz = nums.size(); i < sz; i++) {
            mp[nums[i - k - 1]]--;
            if (mp[nums[i]]) return true;
            mp[nums[i]]++;
        }
        return false;
    }
};
// @lc code=end

