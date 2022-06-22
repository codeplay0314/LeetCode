/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
    int find_k(vector<int>& nums, int l, int r, int k) {
        if (l + 1 == r) return nums[l];
        int index = l + rand() % (r - l);
        int pivot = nums[index];
        swap(nums[r - 1], nums[index]);
        index = l;
        for (int i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[index++]);
            }
        }
        if (index == l + k) return pivot;
        else if (index > l + k) return find_k(nums, l, index - 1, k);
        else return find_k(nums, index, r, k - (index - l));
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find_k(nums, 0, nums.size(), nums.size() - k + 1);
    }
};
// @lc code=end

