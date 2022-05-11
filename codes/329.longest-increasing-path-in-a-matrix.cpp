/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
    int n, m;
    inline int get(int x, int y) {
        return x * m + y;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        int num = n * m;
        vector<int> ind(num, 0);
        vector<vector<int>> nxt(num, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 < n) {
                    if (matrix[i][j] < matrix[i + 1][j]) {
                        ind[get(i, j)]++;
                        nxt[get(i + 1, j)].push_back(get(i, j));
                    } else if (matrix[i][j] > matrix[i + 1][j]) {
                        ind[get(i + 1, j)]++;
                        nxt[get(i, j)].push_back(get(i + 1, j));
                    }
                }
                if (j + 1 < m) {
                    if (matrix[i][j] < matrix[i][j + 1]) {
                        ind[get(i, j)]++;
                        nxt[get(i, j + 1)].push_back(get(i, j));
                    } else if (matrix[i][j] > matrix[i][j + 1]) {
                        ind[get(i, j + 1)]++;
                        nxt[get(i, j)].push_back(get(i, j + 1));
                    }
                }
            }
        }
        queue<int> q;
        vector<int> length(num, 1);
        int ans = 1;
        for (int i = 0; i < num; i++) {
            if (!ind[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : nxt[u]) {
                if (!--ind[v]) {
                    q.push(v);
                    length[v] = max(length[v], length[u] + 1);
                    ans = max(ans, length[v]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

