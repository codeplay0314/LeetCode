/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
    const int move[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int n;
    inline bool in(int x) {
        return 0 <= x && x < n;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, n * n + 1));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        dis[0][0] = 1;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            if (p.first == n - 1 && p.second == n - 1) return dis[p.first][p.second];
            q.pop();
            for (int i = 0; i < 8; i++) {
                int x = p.first + move[i][0];
                int y = p.second + move[i][1];
                if (in(x) && in(y) && !grid[x][y] && dis[x][y] > dis[p.first][p.second] + 1) {
                    q.push(make_pair(x, y));
                    dis[x][y] = dis[p.first][p.second] + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

