/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
class Solution {
    static const int maxh = 2e4;
    static constexpr int dx[] = {0, 0, 1, -1};
    static constexpr int dy[] = {1, -1, 0, 0};
    vector<vector<pair<int, int>>> stp;
public:
    Solution() : stp(maxh + 1) {}
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        int H = 1;

        vector<vector<bool>> field(n, vector<bool>(m, true));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                stp[heightMap[i][j]].push_back({i, j});
                H = max(H, heightMap[i][j]);
            }
        }

        int solid = n * m;
        int leaked = 0;
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int h = 1; h <= H; h++) {
            for (auto p : stp[h - 1]) {
                int x = p.first;
                int y = p.second;
                field[x][y] = false;
                solid--;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) {
                        q.push({x, y});
                        break;
                    }
                }
            }

            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if (vis[x][y]) continue;

                vis[x][y] = true;
                leaked++;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || field[nx][ny]) continue;
                    q.push({nx, ny});
                }
            }

            ans += n * m - solid - leaked;
        }

        return ans;
    }
};
// @lc code=end
