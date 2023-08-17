/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
    static constexpr int mv[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    inline bool in(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<vector<int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!mat[i][j]) {
                    ans[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int x = cur[0], y = cur[1], d = cur[2];
            for (int k = 0; k < 4; k++) {
                int nx = x + mv[k][0], ny = y + mv[k][1];
                if (in(nx, ny) && ans[nx][ny] > d + 1) {
                    ans[nx][ny] = d + 1;
                    q.push({nx, ny, d + 1});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

