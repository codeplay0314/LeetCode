/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class UnionFind {
public:
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void unite(int x, int y) { fa[find(x)] = find(y); }
    UnionFind(int _n) : n(_n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
private:
    int n;
    vector<int> fa;
};

class Solution {
    const int maxh = 1e6;
    int n, m;
    bool check(int eff, vector<vector<int>>& heights) {
        UnionFind uf(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && abs(heights[i][j] - heights[i - 1][j]) <= eff) uf.unite(i * m + j, (i - 1) * m + j);
                if (j && abs(heights[i][j] - heights[i][j - 1]) <= eff) uf.unite(i * m + j, i * m + (j - 1));
            }
        }
        return uf.find(0) == uf.find(n * m - 1);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        int l = 0, r = maxh;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, heights)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

