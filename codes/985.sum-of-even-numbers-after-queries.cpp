/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 */

// @lc code=start
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size(), cur = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                cur += nums[i];
            }
        }
        for (vector<int> q : queries) {
            if (nums[q[1]] % 2 == 0) {
                cur -= nums[q[1]];
            }
            nums[q[1]] += q[0];
            if (nums[q[1]] % 2 == 0) {
                cur += nums[q[1]];
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
// @lc code=end

