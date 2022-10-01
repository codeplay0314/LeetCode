/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        int ans1 = l;
        l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        int ans2 = r;
        if (ans1 > ans2) ans1 = ans2 = -1;
        return vector<int>{ans1, ans2};
    }
};
// @lc code=end

