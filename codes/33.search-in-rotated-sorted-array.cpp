/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    int exist(vector<int>& nums, int x, int y, int target) {
        int l = x, r = y - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        if (l >= y) return -1;
        return nums[l] == target ? l : -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 1, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[0]) r = mid - 1;
            else l = mid + 1;
        }
        int res = exist(nums, 0, l, target);
        if (res < 0) res = exist(nums, l, n, target);
        return res;
    }
};
// @lc code=end

