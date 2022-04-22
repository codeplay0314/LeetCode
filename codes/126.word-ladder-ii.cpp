/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start

const int inf = ~0u>>1;

class Tokenizer {
    map<string, int> mp;
    vector<string> dic;
    int nums = 0;
public:
    int get(string str) {
        if (mp.find(str) != mp.end()) return mp[str];
        dic.push_back(str);
        return mp[str] = nums++;
    }
    string get(int x) {
        return dic[x];
    }
    int size() {
        return nums;
    }
};

class Graph {
    int N;
    vector<vector<int>> E;
public:
    Graph(int n) : E(n), N(n) {}
    void addEdge(int u, int v) {
        E[u].push_back(v);
        E[v].push_back(u);
    }
    void dfs(int u, int T, vector<int>& dis, vector<string>& path, vector<vector<string>>& ans, Tokenizer& tk) {
        path.push_back(tk.get(u));
        if (u == T) {
            ans.push_back(vector<string>(path));
        } else {
            for (auto v : E[u]) {
                if (dis[v] == dis[u] + 1) {
                    dfs(v, T, dis, path, ans, tk);
                }
            }
        }
        path.pop_back();
    }
    void ShortestPath(int S, int T, vector<int>& dis) {
        queue<int> q;
        q.push(S), dis[S] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : E[u]) {
                if (dis[v] == inf) {
                    q.push(v), dis[v] = dis[u] + 1;
                }
                if (dis[T] != inf) break;
            }
            if (dis[T] != inf) break;
        }
    }
};

class Solution {
    bool diffSingle(string& s1, string& s2) {
        int diff = 0, len = s1.size();
        for (int i = 0; i < len && diff < 2; i++) {
            diff += s1[i] != s2[i];
        }
        return diff == 1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        Tokenizer tk;
        tk.get(beginWord);
        for (auto word : wordList) tk.get(word);
        int n = tk.size();
        Graph G(n);
        int begin = tk.get(beginWord), end = tk.get(endWord);
        if (n > wordList.size()) {
            for (auto x : wordList) {
                if (diffSingle(beginWord, x)) G.addEdge(begin, tk.get(x));
            }
        }
        for (int i = 0, wl = wordList.size(); i < wl; i++) {
            string x = wordList[i];
            int u = tk.get(x);
            for (int j = i + 1; j < wl; j++) {
                string y = wordList[j];
                int v = tk.get(y);
                if (diffSingle(x, y)) G.addEdge(u, v);
            }
        }
        
        vector<int> dis(tk.size(), inf);
        G.ShortestPath(begin, end, dis);

        vector<string> path;        
        vector<vector<string>> ans;
        G.dfs(begin, end, dis, path, ans, tk);
        return ans;
    }
};
// @lc code=end

