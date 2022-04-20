/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
    const static int inf = ~0u>>1;
    class Counter {
        int sum[52];
        bool check[52];
        int not0 = 0;
    public:
        Counter() {
            memset(sum, 0, sizeof(sum));
            memset(check, 0, sizeof(check));
        }
        void checkin(char c) {
            int x = c <= 'Z' ? c - 'A' : c - 'a' + 26;
            check[x] = true;
        }
        void add(char c) {
            int x = c <= 'Z' ? c - 'A' : c - 'a' + 26;
            if (check[x] && sum[x] == 0) not0++;
            sum[x]++;
        }
        void del(char c) {
            int x = c <= 'Z' ? c - 'A' : c - 'a' + 26;
            if (check[x] && sum[x] == 1) not0--;
            sum[x]--;
        }
        bool cleared() {
            return !not0;
        }
    }cnt;
public:
    string minWindow(string s, string t) {
        int l, len = inf;
        for (auto c : t) {
            cnt.checkin(c);
            cnt.add(c);
        }
        for (int i = 0, j = 0, slen = s.size(), tlen = t.size(); i < slen; i++) {
            while (j < slen && !cnt.cleared()) cnt.del(s[j++]);
            if (cnt.cleared()) {
                if (j - i < len) l = i, len = j - i;
            }
            else break;
            cnt.add(s[i]);
        }
        return len == inf ? "" : s.substr(l, len);
    }
};
// @lc code=end

