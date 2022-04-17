class TrieNode {
private:
    static const int CharSetSIZE = 26;

public:
    bool isleaf = true;
    vector<int> nums;
    TrieNode* nxt[CharSetSIZE];
    
    TrieNode() {
        nums.clear();
        for (int i = 0; i < CharSetSIZE; i++) nxt[i] = NULL;
    }

    void add(string& word, int pos, int num) {
        if (pos == word.size()) {
            nums.push_back(num);
            return;
        }

        isleaf = false;
        int c = word[pos] - 'a';
        if (nxt[c] == NULL) {
            nxt[c] = new TrieNode;
        }
        nxt[c]->add(word, pos + 1, num);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void add(string& word, int num) {
        root->add(word, 0, num);
    }
    
    TrieNode* root;
};

class Solution {
private:
    Trie trie;
    int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<bool>> path;
    int n, m;

    set<int> ans;

    inline bool in(int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }

    void searchWord(vector<vector<char>>& board, int x, int y, TrieNode* node) {
        int c = board[x][y] - 'a';
        TrieNode* nxt = node->nxt[c];

        if (nxt == NULL) return;
        if (!nxt->nums.empty()) {
            for (auto num : nxt->nums) {
                ans.insert(num);
            }
        }
        if (nxt->isleaf) return;

        path[x][y] = true;
        for (int k = 0; k < 4; k++) {
            int nxti = x + dir[k][0], nxtj = y + dir[k][1];
            if (in(nxti, nxtj) && !path[nxti][nxtj]) {
                searchWord(board, nxti, nxtj, node->nxt[c]);
            }
        }
        path[x][y] = false;
    }

    void preProcess(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            vector<bool> nvec(m, 0);
            path.push_back(nvec);
        }
        
        for (int i = 0; i < words.size(); i++) {
            trie.add(words[i], i);
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        preProcess(board, words);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                searchWord(board, i, j, trie.root);
            }
        }

        vector<string> res;
        for (auto num : ans) {
            res.push_back(words[num]);
        }
        return res;
    }
};
