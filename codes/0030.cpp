class Tokenizer {
private:
    int tot = 0;
    map<string, int> num;
    map<string, int> sum;
public:
    void add(string& str) {
        int s = sum[str];
        if (s == 0) num[str] = ++tot;
        sum[str]++;
    }
    int getNum(string& str) {
        int s = sum[str];
        if (s == 0) num[str] = ++tot;
        return num[str];
    }
    int getSum(string& str) {
        return sum[str];
    }
    void getAll(vector<string>& dic) {
        dic.clear();
        for (map<string, int>::iterator it = num.begin(); it != num.end(); it++) {
            dic.push_back(it->first);
        }
    }
};

class KMP {
private:
    string& S;
    vector<int> nxt;
public:
    KMP(string& str, int n) : S(str), nxt(n) {
        nxt[0] = -1;
        for (int i = 1, j = -1; i < n; i++) {
            while (j >= 0 && S[i] != S[j + 1]) j = nxt[j];
            if (S[i] == S[j + 1]) j++;
            nxt[i] = j;
        }
    }
    void match(string& T, vector<int>& f, int num) {
        int n = S.size(), m = T.size();
        for (int i = 0, j = -1; i < m; i++) {
            while (j >= 0 && T[i] != S[j + 1]) j = nxt[j];
            if (T[i] == S[j + 1]) j++;
            if (j + 1 == n) {
                f[i] = num;
                j = nxt[j];
            }
        }
    }
};

class Counter {
private:
    int notZero = 0;
    vector<int> cnt;
public:
    Counter(vector<string>& dic, Tokenizer& tk) : cnt(dic.size() + 1, 0) {
        for (auto word : dic) {
            cnt[tk.getNum(word)] = tk.getSum(word);
            notZero++;
        }
    }
    void add(int x) {
        if (cnt[x] == 0) notZero++;
        cnt[x]++;
        if (cnt[x] == 0) notZero--;
    }
    void del(int x) {
        if (cnt[x] == 0) notZero++;
        cnt[x]--;
        if (cnt[x] == 0) notZero--;
    }
    bool cleared() {
        return notZero == 0;
    }
};

class Solution {
private:
    Tokenizer tk;
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.size();
        
        vector<string> dic;
        for (auto word : words) {
            tk.add(word);
        }        
        tk.getAll(dic);
        
        vector<int> matched(len, 0);
        for (auto word : dic) {
            KMP kmp(word, word.size());
            kmp.match(s, matched, tk.getNum(word));
        }
        
        vector<int> ans;
        int word_num = words.size(), word_len = words[0].size();
        for (int i = 0; i < word_len && i + word_num * word_len <= len; i++) {
            Counter cnt(dic, tk);
            for (int j = 0; j < word_num; j++) {
                int pos = i + (j + 1) * word_len - 1;
                int num = matched[pos];
                if (num != 0) cnt.del(num);
            }
            if (cnt.cleared()) ans.push_back(i);
            for (int j = 1; i + (j + word_num) * word_len <= len; j++) {
                int num = matched[i + j * word_len - 1];
                if (num != 0) cnt.add(num);
                num = matched[i + (j + word_num) * word_len - 1];
                if (num != 0) cnt.del(num);
                if (cnt.cleared()) ans.push_back(i + j * word_len);
            }
        }
        
        return ans;
    }
};