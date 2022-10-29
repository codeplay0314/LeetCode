/*
 * @lc app=leetcode id=2136 lang=cpp
 *
 * [2136] Earliest Possible Day of Full Bloom
 */

// @lc code=start
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();

        vector<pair<int, int>> pr(n);
        for (int i = 0; i < n; i++) {
            pr[i] = make_pair(growTime[i], plantTime[i]);
        }
        sort(pr.begin(), pr.end(), greater<pair<int, int>>());
        
        int ans = 0;
        for (int i = 0, cur = 0; i < n; i++) {
            cur += pr[i].second;
            if (ans < cur + pr[i].first) {
                ans = cur + pr[i].first;
            }
        }
        return ans;
    }
};
// @lc code=end

