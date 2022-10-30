/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
    static const int maxn = 40;
    int dp[maxn][maxn][maxn * maxn + 1];
    int n, m, k;
    const int mv[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    inline bool in(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }
    int search(int x, int y, int e, vector<vector<int>>& grid) {
        if (dp[x][y][e] >= 0) return dp[x][y][e];
        if (x == y && y == 0) return dp[x][y][e] = 0;

        int res = dp[x][y][e] = n * m;
        for (int t = 0; t < 4; t++) {
            int nx = x + mv[t][0], ny = y + mv[t][1];
            if (in(nx, ny)) {
                int ne = e - grid[nx][ny];
                if (ne >= 0) {
                    res = min(res, search(nx, ny, ne, grid) + 1);
                }
            }
        }
        return dp[x][y][e] = res;
    }
public:
    int shortestPath(vector<vector<int>>& grid, int _k) {
        n = grid.size(), m = grid[0].size();
        k = _k;
        memset(dp, -1, sizeof(dp));
        memset(dp[0][0], 0, sizeof(dp[0][0]));
        int ans = search(n - 1, m - 1, k, grid);
        return ans < n * m ? ans : -1;
    }
};
// @lc code=end
