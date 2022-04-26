/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start

class Edge {
public:
    int u, v, w;
    bool operator < (const Edge& E) const {
        return w < E.w;
    }
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

class MGT {
    int n;
    vector<int> fa;
    vector<Edge> edges;

    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool unite(int x, int y) {
        int u = find(x), v = find(y);
        if (u == v) return false;
        fa[u] = v;
        return true;
    }
public:    
    void AddEdge(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
    }
    int Solve() {
        sort(edges.begin(), edges.end());
        int ans = 0, res = n - 1;
        for (auto e : edges) {
            if (unite(e.u, e.v)) {
                ans += e.w;
                if (!--res) break;
            }
        }
        return ans;
    }
    MGT(int _n) : n(_n), fa(n) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        MGT mgt(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                mgt.AddEdge(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
        return mgt.Solve();
    }
};
// @lc code=end

