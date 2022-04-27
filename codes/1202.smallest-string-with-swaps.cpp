/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
class UnionFind {
    int n;
    vector<int> fa;
public:
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void unite(int u, int v) {
        fa[find(u)] = find(v);
    }

    UnionFind(int _n) : n(_n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionFind uf(n);
        for (auto pair : pairs) {
            uf.unite(pair[0], pair[1]);
        }
        vector<vector<int>> pos(n);
        vector<vector<char>> val(n);
        for (int i = 0; i < n; i++) {
            pos[uf.find(i)].push_back(i);
            val[uf.find(i)].push_back(s[i]);
        }
        for (int i = 0; i < n; i++) {
            int size = pos[i].size();
            if (size) {
                sort(val[i].begin(), val[i].end());
                for (int j = 0; j < size; j++) {
                    s[pos[i][j]] = val[i][j];
                }
            }
        }
        return s;
    }
};
// @lc code=end

