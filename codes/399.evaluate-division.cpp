/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Tokenizer {
public:
    bool find(string& str) {
        return mp.find(str) != mp.end();
    }
    int get(string& str) {
        if (!find(str)) add(str);
        return mp[str];
    }
    int size() {
        return _size;
    }
private:
    unordered_map<string, int> mp;
    int _size = 0;
    void add(string& str) {
        mp[str] = _size++;
    }
};

class UnionFind {
public:
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void unite(int x, int y) {
        fa[find(x)] = find(y);
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    UnionFind(int n) : _size(n), fa(vector<int>(n)) {
        for (int i = 0; i < n; i++) fa[i] = i;
    }
private:
    vector<int> fa;
    int _size;
};

class Graph {
public:
    void addEdge(int u, int v, double _w) {
        to[u].push_back(v);
        w[u].push_back(_w);
    }
    Graph(int n) : to(n, vector<int>()), w(n, vector<double>()) {}
    
    vector<vector<int>> to;
    vector<vector<double>> w;
};

class Solution {
    void BFS(int S, Graph& G, UnionFind& uf, vector<bool>& vis, vector<double>& value) {
        if (vis[S]) return;
        queue<int> q;
        q.push(S);
        vis[S] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int e_size = G.to[u].size();
            for (int i = 0; i < e_size; i++) {
                int v = G.to[u][i];
                if (!vis[v]) {
                    uf.unite(u, v);
                    value[v] = value[u] / G.w[u][i];
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Tokenizer tk;
        for (auto eq : equations) {
            tk.get(eq[0]);
            tk.get(eq[1]);
        }

        int n = tk.size();
        Graph G(n);
        int eq_num = equations.size();
        for (int i = 0; i < eq_num; i++) {
            int u = tk.get(equations[i][0]);
            int v = tk.get(equations[i][1]);
            G.addEdge(u, v, values[i]);
            G.addEdge(v, u, 1 / values[i]);
        }

        vector<double> value = vector<double>(n, 1);
        vector<bool> vis(n, false);
        UnionFind uf(n);
        for (int i = 0; i < n; i++) BFS(i, G, uf, vis, value);

        vector<double> ans;
        for (auto query : queries) {
            if (!tk.find(query[0]) || !tk.find(query[1])) {
                ans.push_back(-1);
                continue;
            }
            int u = tk.get(query[0]);
            int v = tk.get(query[1]);
            if (!uf.connected(u, v)) ans.push_back(-1);
            else ans.push_back(value[u] / value[v]);
        }

        return ans;
    }
};
// @lc code=end

