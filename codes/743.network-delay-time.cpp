/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
const int inf = ~0u>>1;
class Graph {
public:
    void addEdge(int u, int v, int w) {
        _to[u].push_back(v);
        _w[u].push_back(w);
    }
    int Dij(int S) {
        vector<int> dis(_n, inf);        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dis[S] = 0;
        q.push(make_pair(dis[S], S));
        while (!q.empty()) {
            pair<int, int> p = q.top();
            q.pop();
            if (p.first != dis[p.second]) continue;
            int u = p.second;
            for (int i = 0, size = _to[u].size(); i < size; i++) {
                int v = _to[u][i], w = _w[u][i];
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push(make_pair(dis[v], v));
                }
            }
        }
        int ans = 0;
        for (int d : dis) {
            if (d == inf) return -1;
            ans = max(ans, d);
        }
        return ans;
    }
    Graph(int n) : _n(n), _to(n, vector<int>()), _w(n, vector<int>()) {}
private:
    int _n;
    vector<vector<int>> _to, _w;
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph G(n);
        for (vector<int> time : times) {
            G.addEdge(time[0] - 1, time[1] - 1, time[2]);
        }
        return G.Dij(k - 1);
    }
};
// @lc code=end

