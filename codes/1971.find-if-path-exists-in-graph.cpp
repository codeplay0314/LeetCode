/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
    class UnionFind {
        vector<int> fa;
    public:
        UnionFind(int n) : fa(n) {
            for (int i = 0; i < n; i++) fa[i] = i;
        }
        int find(int x) {
            return x == fa[x] ? fa[x] : fa[x] =  find(fa[x]);
        }
        bool united(int x, int y) {
            return find(x) == find(y);
        }
        void unite(int x, int y) {
            int u = find(x), v = find(y);
            if (u != v) fa[u] = v;
        }
    };
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        for (vector<int> edge : edges) {
            uf.unite(edge[0], edge[1]);
        }
        return uf.united(source, destination);
    }
};
// @lc code=end

