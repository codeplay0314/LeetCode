/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class KMP {
public:
    int match(string& T) {
        int n = T.size(), ans = 0;
        for (int i = 0, j = -1; i < n; i++) {
            while (j >= 0 && T[i] != S[j + 1]) j = nxt[j];
            if (T[i] == S[j + 1]) j++;
            if (i == n - 1) ans = j;
            if (j == len - 1) j = nxt[j];
        }
        return ans;
    }
    KMP(string& s) : len(s.size()), S(s), nxt(len) {
        nxt[0] = -1;
        for (int i = 1, j = -1; i < len; i++) {
            while (j >= 0 && S[i] != S[j + 1]) j = nxt[j];
            if (S[i] == S[j + 1]) j++;
            nxt[i] = j;
        }
    }
private:
    int len;
    string S;
    vector<int> nxt;
};

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() == 0) return s;
        string rev(s);
        reverse(rev.begin(), rev.end());
        KMP kmp(s);
        return rev.substr(0, s.size() - kmp.match(rev) - 1) + s;
    }
};
// @lc code=end

