/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
    string target;
    int len;
    int n, m;

    bool vis[6][6];
    const int mv[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    inline bool in(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }
    bool found(int x, int y, const vector<vector<char>>& board, int t) {
        vis[x][y] = true;
        bool res = false;
        if (board[x][y] == target[t]) {
            if (t == len - 1) res = true;
            else {
                for (int k = 0; k < 4; k++) {
                    int xx = x + mv[k][0], yy = y + mv[k][1];
                    if (in(xx, yy) && !vis[xx][yy] && found(xx, yy, board, t + 1)) {
                        res = true;
                        break;
                    }
                }
            }
        }
        vis[x][y] = false;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        target = word;
        len = target.size();
        n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (found(i, j, board, 0)) return true;
            }
        }
        return false;
    }
};
// @lc code=end

