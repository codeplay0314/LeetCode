/*
 * @lc app=leetcode id=2279 lang=cpp
 *
 * [2279] Maximum Bags With Full Capacity of Rocks
 */

// @lc code=start
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> rest(n);
        for (int i = 0; i < n; i++) {
            rest[i] = capacity[i] - rocks[i];
        }
        sort(rest.begin(), rest.end());
        int ans;
        for (ans = 0; ans < n; ans++) {
            if (additionalRocks < rest[ans]) break;
            additionalRocks -= rest[ans];
        }
        return ans;
    }
};
// @lc code=end

