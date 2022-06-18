/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [745] Prefix and Suffix Search
 */

// @lc code=start
class WordFilter {
    typedef unsigned long long ll;
    static const ll p = 23333;
    unordered_map<ll, set<int>> pre, suf;
    set<string> exist;
public:
    WordFilter(vector<string>& words) {
        for (int i = words.size() - 1; i >= 0; i--) {
            if (exist.find(words[i]) != exist.end()) continue;
            exist.insert(words[i]);
            ll cur = 0, pp = 1;
            for (char c : words[i]) {
                cur = cur * p + c;
                pre[cur].insert(i);
            }
            cur = 0;
            for (int j = words[i].length() - 1; j >= 0; j--) {
                cur += pp * words[i][j];
                suf[cur].insert(i);
                pp *= p;
            }
        }
    }
    
    int f(string prefix, string suffix) {
        ll pref = 0, suff = 0;
        for (char c : prefix) {
            pref = pref * p + c;
        }
        for (char c : suffix) {
            suff = suff * p + c;
        }
        set<int, greater<int>> st;
        set_intersection(pre[pref].begin(), pre[pref].end(), suf[suff].begin(), suf[suff].end(), inserter(st, st.begin()));
        if (st.size() == 0) return -1;
        return *st.begin();
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end

