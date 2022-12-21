/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
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
            return x == fa[x] ? x : fa[x] = find(fa[x]);
        }
        bool united(int x, int y) {
            return find(x) == find(y);
        }
        void unite(int x, int y) {
            fa[find(x)] = find(y);
        }
    };
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        UnionFind uf(2 * n);
        for (auto p : dislikes) {
            uf.unite(p[0] - 1, p[1] + n - 1);
            uf.unite(p[0] + n - 1, p[1] - 1);
        }
        for (int i = 0; i < n; i++) {
            if (uf.united(i, i + n)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

