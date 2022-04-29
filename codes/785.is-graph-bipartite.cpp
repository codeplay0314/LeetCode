/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [801] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
    vector<int> color;
    bool check(int st, vector<vector<int>>& G) {
        if (color[st] >= 0) return true;
        
        color[st] = 0;
        queue<int> q;
        q.push(st);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : G[u]) {
                if (color[v] >= 0) {
                    if (color[u]^color[v] == 0) return false;
                } else {
                    color[v] = color[u]^1;
                    q.push(v);
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int>(n, -1);
        for (int i = 0; i < n; i++)
            if (!check(i, graph))
                return false;
        return true;
    }
};
// @lc code=end

