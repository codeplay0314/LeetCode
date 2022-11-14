/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class UnionFind {
    vector<int> fa;
public:
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool unite(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) return false;
        fa[v] = u;
        return true;
    }
    UnionFind(int n) : fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    };
};

class Solution {
    inline bool InLine(const vector<int>& p1, const vector<int>& p2) {
        return p1[0] == p2[0] || p1[1] == p2[1];
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (InLine(stones[i], stones[j]) && uf.unite(i, j)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

