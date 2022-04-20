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
                if (p[j - 1] == '?') {
                    if (i) f[i][j] = f[i - 1][j - 1];
                    else f[i][j] = 0;
                } else if (p[j - 1] == '*') {
                    for (int k = 0; k <= i; k++)
                        f[i][j] |= f[k][j - 1];
                } else {
                    if (i > 0 && s[i - 1] == p[j - 1]) f[i][j] = f[i - 1][j - 1];
                    else f[i][j] = false;
                }
            }
        }
        
        return f[slen][plen];
    }
};