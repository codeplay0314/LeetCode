/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution {
    int n;
    vector<vector<int>> edges;
    vector<int> fa, num, sum, ans;

    void DFS1(int u) {
        num[u] = 1;
        sum[u] = 0;
        for (int v : edges[u]) {
            if (v != fa[u]) {
                fa[v] = u;
                DFS1(v);
                num[u] += num[v];
                sum[u] += sum[v] + num[v];
            }
        }
    }

    void DFS2(int u, int head) {
        ans[u] = sum[u] + head;
        int tot = 0;
        for (int v : edges[u]) {
            if (v != fa[u]) {
                DFS2(v, head + sum[u] - sum[v] + n - 2 * num[v]);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int _n, vector<vector<int>>& _edges) {
        n = _n;
        edges = vector<vector<int>>(n);
        fa = vector<int>(n);
        num = vector<int>(n);
        sum = vector<int>(n);
        ans = vector<int>(n);
        fa[0] = -1;

        for (vector<int> p : _edges) {
            edges[p[0]].push_back(p[1]);
            edges[p[1]].push_back(p[0]);
        }

        DFS1(0);
        DFS2(0, 0);

        return ans;
    }
};
// @lc code=end

