/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int tot = neededTime[0], maxt = tot;
        for (int i = 1; i < neededTime.size(); i++) {
            if (colors[i] != colors[i - 1]) {
                ans += tot - maxt;
                tot = maxt = 0;
            }            
            tot += neededTime[i];
            maxt = max(maxt, neededTime[i]);
        }
        ans += tot - maxt;
        return ans;
    }
};
// @lc code=end

