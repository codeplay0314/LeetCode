/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start

const int inf = ~0u>>1;

class Tokenizer {
    unordered_map<string, int> mp;
    int nums = 0;
public:
    inline bool exist(string& str) {
        return mp.find(str) != mp.end();
    }
    int get(string str) {
        if (exist(str)) return mp[str];
        return mp[str] = nums++;
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
    int ShortestPath(int S, int T) {
        int cnt = 0;
        queue<int> q;
        vector<vector<int>> dis(2, vector<int>(N, inf));
        q.push(S), dis[0][S] = 0;
        q.push(T), dis[1][T] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int t = 0; t < 2; t++)
                if (dis[t][u] != inf)
                    for (auto v : E[u]) {
                        if (dis[t][v] == inf) q.push(v), dis[t][v] = dis[t][u] + 1;
                        if (dis[t^1][v] != inf) return dis[0][v] + dis[1][v] + 1;
                    }
        }
        return 0;
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        Tokenizer tk;
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) wordList.push_back(beginWord);
        for (auto word : wordList) tk.get(word);

        if (!tk.exist(endWord)) return 0;

        int n = tk.size();
        Graph G(n);
        for (int i = 0; i < n; i++) {
            string x = wordList[i];
            for (int j = i + 1; j < n; j++) {
                string y = wordList[j];
                if (diffSingle(x, y)) G.addEdge(i, j);
            }
        }
        
        return G.ShortestPath(tk.get(beginWord), tk.get(endWord));
    }
};
// @lc code=end