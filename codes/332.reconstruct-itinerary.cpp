/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Tokenizer {
public:
    void add(const string& s) {
        _st.insert(s);
    }
    void build() {
        _strs.assign(_st.begin(), _st.end());
        for (string str : _strs) {
            _mp[str] = _n++;
        }
    }
    int get(const string& s) {
        return _mp[s];
    }
    string get(int x) {
        return _strs[x];
    }
    int size() {
        return _n;
    }
private:
    int _n = 0;
    set<string> _st;
    vector<string> _strs;
    unordered_map<string, int> _mp;
};

class Graph {
public:
    void addEdge(int dep, int des) {
        _edges[dep].push_back(des);
        _vis[dep].push_back(false);
        _not_visited++;
    }
    void sort() {
        for (vector<int>& edges : _edges) {
            std::sort(edges.begin(), edges.end());
        }
    }
    vector<int> dfs(int u) {
        for (int i = 0, lim = _edges[u].size(); i < lim; i++) {
            if (!_vis[u][i]) {
                _vis[u][i] = true;
                _not_visited--;
                vector<int> it = dfs(_edges[u][i]);
                if (_not_visited == 0) {
                    it.insert(it.begin(), u);
                    return it;
                }
                _vis[u][i] = false;
                _not_visited++;
            }
        }
        return vector<int>{u};
    }
    Graph(int n) : _n(n), _edges(n, vector<int>()), _vis(n, vector<bool>()) {}
private:
    int _n;
    vector<vector<int>> _edges;
    vector<vector<bool>> _vis;
    int _not_visited = 0;
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        Tokenizer tk;
        for (vector<string> ticket : tickets) {
            tk.add(ticket[0]);
            tk.add(ticket[1]);
        }
        tk.build();
        Graph G(tk.size());
        for (vector<string> ticket : tickets) {
            G.addEdge(tk.get(ticket[0]), tk.get(ticket[1]));
        }
        G.sort();
        vector<int> res = G.dfs(tk.get("JFK"));
        vector<string> ans;
        for (int no : res) {
            ans.push_back(tk.get(no));
        }
        return ans;
    }
};
// @lc code=end

