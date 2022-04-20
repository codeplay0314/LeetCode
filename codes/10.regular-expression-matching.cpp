/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        
        bool f[slen + 1][plen + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        
        for (int i = 0; i <= slen; i++) {
            for (int j = 1; j <= plen; j++) {
                if (p[j - 1] == '.') {
                    if (i) f[i][j] = f[i - 1][j - 1];
                    else f[i][j] = 0;
                } else if (p[j - 1] == '*') {
                    if (p[j - 2] == '.') {
                        for (int k = 0; i - k >= 0 && j - 2 >= 0; k++) {
                            f[i][j] |= f[i - k][j - 2];
                        }
                    } else {
                        f[i][j] = f[i][j - 2];
                        for (int k = i - 1; k >= 0 && s[k] == p[j - 2]; k--) {
                            f[i][j] |= f[k][j - 2];
                        }
                    }
                } else {
                    if (i > 0 && s[i - 1] == p[j - 1]) f[i][j] = f[i - 1][j - 1];
                    else f[i][j] = false;
                }
            }
        }
        
        return f[slen][plen];
    }
};
// @lc code=end

