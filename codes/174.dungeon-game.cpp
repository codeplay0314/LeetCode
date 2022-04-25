/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
    const int inf = ~0u>>1;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        int dp[n][m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = min(0, dungeon[i][j]);
                int route = -inf;
                if (i + 1 < n) route = max(route, dp[i + 1][j]);
                if (j + 1 < m) route = max(route, dp[i][j + 1]);
                if (route != -inf) dp[i][j] = min(dp[i][j], dungeon[i][j] + route);
            }
        return max(0, -dp[0][0]) + 1;
    }
};
// @lc code=end

