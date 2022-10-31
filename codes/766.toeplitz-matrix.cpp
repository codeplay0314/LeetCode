/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int k = -n + 1; k < m; k++) {
            for (int i = max(0, -k), j = max(0, k), num = -1; i < n && j < m; i++, j++) {
                if (num < 0) num = matrix[i][j];
                else if (num != matrix[i][j]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

