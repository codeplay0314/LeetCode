/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution {
    static const int maxn = 50;
    static const int maxk = 10;
    static const int mod = 1e9 + 7;
    int dp[maxk][maxn][maxn];
    int apple[maxn + 1][maxn + 1];
    inline bool exist(int x1, int y1, int x2, int y2) {
        return apple[x2][y2] - apple[x1][y2] - apple[x2][y1] + apple[x1][y1] > 0;
    }
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                apple[i][j] = apple[i - 1][j] + apple[i][j - 1] - apple[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[0][i][j] = exist(i, j, n, m);
            }
        }
        for (int t = 1; t < k; t++) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    for (int l = i + 1; l < n; l++) {
                        if (exist(i, j, l, m))
                            dp[t][i][j] = (dp[t][i][j] + dp[t - 1][l][j]) % mod;
                    }
                    for (int l = j + 1; l < m; l++) {
                        if (exist(i, j, n, l))
                            dp[t][i][j] = (dp[t][i][j] + dp[t - 1][i][l]) % mod;
                    }
                }
            }
        }
        return dp[k - 1][0][0];
    }
};
// @lc code=end

