/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
    void Manacher(string& str, int len, int slen, vector<int>& palin) {
        string s(slen, '#');
        for (int i = 0; i < len; i++) {
            s[i * 2 + 1] = str[i];
        }
        for (int i = 0, l = 0, r = -1; i < slen; i++) {
            int j = l + r - i;
            if (j >= 0) palin[i] = max(palin[i], min(palin[j], r - j + 1));
            while (i - palin[i] >= 0 &&  i + palin[i] < slen && s[i - palin[i]] == s[i + palin[i]]) palin[i]++;
        }
    }
public:
    int countSubstrings(string s) {
        int len = s.length();
        int slen = 2 * len + 1;
        vector<int> palin(slen, 1);
        Manacher(s, len, slen, palin);
        
        int ans = 0;
        for (int i = 0; i < slen; i++) {
            ans += (palin[i] + (i&1)) / 2;
        }
        return ans;
    }
};
// @lc code=end

