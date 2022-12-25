/*
 * @lc app=leetcode id=2389 lang=cpp
 *
 * [2389] Longest Subsequence With Limited Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> ans(m);
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) nums[i] += nums[i - 1];
        for (int i = 0, j; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (nums[j] > queries[i]) break;
            }
            ans[i] = j;
        }
        return ans;
    }
};
// @lc code=end

