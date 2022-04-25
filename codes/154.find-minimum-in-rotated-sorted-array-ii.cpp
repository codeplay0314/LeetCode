/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
    const int inf = ~0u>>1;
    int bsearch(vector<int>& nums, int l, int r) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (l == mid) return min(nums[l], nums[r]);
            if (nums[mid - 1] > nums[mid]) return nums[mid];
            if (nums[l] > nums[mid]) r = mid - 1;
            else if (nums[mid] > nums[r]) l = mid + 1;
            else return min(bsearch(nums, l, mid - 1), bsearch(nums, mid + 1, r));
        }
        return inf;
    }
public:
    int findMin(vector<int>& nums) {
        return bsearch(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

