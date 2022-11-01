/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n  = grid[0].size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int k = i;
            for (int j = 0; j < m; j++) {
                if (grid[j][k] > 0 && k + 1 < n && grid[j][k + 1] > 0) {
                    k++;
                } else if (grid[j][k] < 0 && k > 0 && grid[j][k - 1] < 0) {
                    k--;
                } else {
                    ans[i] = -1;
                    break;
                }
            }
            if (ans[i] != -1) {
                ans[i] = k;
            }
        }
        return ans;
    }
};
// @lc code=end

