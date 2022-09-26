/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class UnionFind {
    vector<int> fa;
public:
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool united(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y) {
        fa[find(x)] = find(y);
    }
    UnionFind(int n) {
        fa = vector<int>(n);
        for (int i = 0; i < n; i++) fa[i] = i;
    }
};

class Solution {
    static const int absize = 26;
    UnionFind uf = UnionFind(absize);
public:
    bool equationsPossible(vector<string>& equations) {
        for (string eq : equations) {
            if (eq[1] == '=') {
                uf.unite(eq[0] - 'a', eq[3] - 'a');
            }
        }
        for (string eq : equations) {
            if (eq[1] == '!') {
                if (uf.united(eq[0] - 'a', eq[3] - 'a')) return false;
            }
        }
        return true;
    }
};
// @lc code=end

