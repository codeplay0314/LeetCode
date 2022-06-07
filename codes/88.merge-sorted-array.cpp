/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        int p1 = 0, p2 = 0;
        while (p1 < m || p2 < n) {
            if (p1 == m) tmp.push_back(nums2[p2++]);
            else if (p2 == n) tmp.push_back(nums1[p1++]);
            else tmp.push_back(nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++]);
        }
        nums1.assign(tmp.begin(), tmp.end());
    }
};
// @lc code=end

