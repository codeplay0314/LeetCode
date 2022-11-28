/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

// @lc code=start
class Solution {
    unordered_map<int, int> mp;
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        for (auto m : matches) {
            mp[m[0]];
            mp[m[1]]++;
        }
        vector<vector<int>> ans(2);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second < 2) {
                ans[it->second].push_back(it->first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
// @lc code=end

