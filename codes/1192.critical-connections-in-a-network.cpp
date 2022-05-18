/*
 * @lc app=leetcode id=1300 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
    vector<vector<int>> ans;

    vector<int> dfn, low;
    vector<vector<int>> edges;
    void dfs(int u, int fa) {
        static int stp = 0;
        dfn[u] = low[u] = stp++;
        for (int v : edges[u]) {
            if (v != fa) {
                if (dfn[v] < 0) dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    ans.push_back(vector<int>{u, v});
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn = vector<int>(n, -1);
        low = vector<int>(n);
        edges = vector<vector<int>>(n);
        for (vector<int> p : connections) {
            edges[p[0]].push_back(p[1]);
            edges[p[1]].push_back(p[0]);
        }
        dfs(0, -1);
        return ans;
    }
};
// @lc code=end

