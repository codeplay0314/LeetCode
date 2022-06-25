/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                if (pos) return false;
                pos = i;
            }
        }
        if (pos < 2 || pos == n - 1) return true;
        if (nums[pos - 2] <= nums[pos]) return true;
        if (nums[pos - 1] <= nums[pos + 1]) return true;
        return false;
    }
};
// @lc code=end

