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
        queue<int> q1, q2;
        vector<int> dis1(N, inf), dis2(N, inf);
        q1.push(S), dis1[S] = 0;
        q2.push(T), dis2[T] = 0;
        int curd = 0;
        while (!q1.empty() || !q2.empty()) {
            while (!q1.empty() && dis1[q1.front()] == curd) {
                cnt++;
                int u = q1.front();
                q1.pop();
                for (auto v : E[u]) {
                    if (dis1[v] == inf) q1.push(v), dis1[v] = dis1[u] + 1;
                    if (dis2[v] != inf) dis1[T] = min(dis1[T], dis1[v] + dis2[v]);
                }
            }
            if (!q2.empty() && dis2[q2.front()] == curd) {
                cnt++;
                int u = q2.front();
                q2.pop();
                for (auto v : E[u]) {
                    if (dis2[v] == inf) q2.push(v), dis2[v] = dis2[u] + 1;
                    if (dis1[v] != inf) dis1[T] = min(dis1[T], dis1[v] + dis2[v]);
                }
            }
            if (dis1[T] != inf) break;
            curd++;
        }
        return dis1[T] == inf ? 0 : dis1[T] + 1;
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