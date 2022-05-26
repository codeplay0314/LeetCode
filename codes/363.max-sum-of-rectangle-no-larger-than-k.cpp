/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int sum[m + 1][n + 1];
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        const int maxn = 1e5;
        int l = -maxn, r = k;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int ii = i; ii <= m; ii++) {
                    for (int jj = j; jj <= n; jj++) {
                        int x = sum[ii][jj] - sum[ii][j - 1] - sum[i - 1][jj] + sum[i - 1][j - 1];
                        if (l <= x && x <= r) {
                            l = x;
                            if (l == r) return l;
                        } 
                    }
                }
            }
        }

        return l;
    }
};
// @lc code=end

