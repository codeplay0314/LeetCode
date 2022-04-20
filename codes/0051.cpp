class Solution {
private:
    int n;
    long long colban = 0, p1ban = 0, p2ban = 0;
    vector<vector<string>> ans;
    
    vector<int> pos;    
    void addAns() {
        vector<string> tmp;
        for (int i = 0; i < n; i++) {
            string line;
            for (int j = 0; j < n; j++)
                line += pos[i] == j ? 'Q' : '.';
            tmp.push_back(line);
        }
        ans.push_back(tmp);
    }
    
    void search(int x) {
        if (x == n) {
            addAns();
            return;
        }
        pos.push_back(-1);
        for (int y = 0; y < n; y++) {
            if (colban & (1<<y)) continue;
            if (p1ban & (1<<(x + y))) continue;
            if (p2ban & (1<<(x - y + n))) continue;
            colban ^= 1<<y;
            p1ban ^= 1<<(x + y);
            p2ban ^= 1<<(x - y + n);
            pos[x] = y;
            search(x + 1);
            colban ^= 1<<y;
            p1ban ^= 1<<(x + y);
            p2ban ^= 1<<(x - y + n);
        }
    }
public:
    vector<vector<string>> solveNQueens(int len) {
        n = len;
        search(0);
        return ans;
    }
};