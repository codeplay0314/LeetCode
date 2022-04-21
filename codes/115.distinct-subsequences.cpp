/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
                else f[i][j] = f[i - 1][j];
        return f[n][m];
    }
};
// @lc code=end

