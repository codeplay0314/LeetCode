/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
    int n, m;
    inline int convert(const vector<int>& v) {
        return v[0] * m + v[1];
    }
    inline vector<int> convert(int t) {
        return vector<int>{t / m, t % m};
    }
    
    int mv[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    inline vector<int> step(const vector<int>& v, int k) {
        return vector<int>{v[0] + mv[k][0], v[1] + mv[k][1]};
    }

    inline bool inbound(const vector<int>& v) {
        return 0 <= v[0] && v[0] < n && 0 <= v[1] && v[1] < m;
    }
    inline bool onedge(const vector<int>& v) {
        return v[0] == 0 || v[0] == n - 1 || v[1] == 0 || v[1] == m - 1;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n = maze.size();
        m = maze[0].size();        
        int vis[n][m];
        memset(vis, -1, sizeof(vis));

        queue<int> q;
        q.push(convert(entrance));
        vis[entrance[0]][entrance[1]] = 0;        
        while (!q.empty()) {
            vector<int> u = convert(q.front());
            q.pop();
            for (int k = 0; k < 4; k++) {
                vector<int> v = step(u, k);
                if (inbound(v) && maze[v[0]][v[1]] == '.' && vis[v[0]][v[1]] < 0) {
                    q.push(convert(v));
                    vis[v[0]][v[1]] = vis[u[0]][u[1]] + 1;
                    if (onedge(v)) {
                        return vis[v[0]][v[1]];
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

