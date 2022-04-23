/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
    inline int inLine(vector<int>& x, vector<int>& y, vector<int>& z) {
        return (y[1] - x[1]) * (z[0] - x[0]) == (z[1] - x[1]) * (y[0] - x[0]);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 1;
        int ans = 2;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int res = 2;
                for (int k = 0; k < n; k++)
                    if (k != i && k != j)
                        res += inLine(points[i], points[j], points[k]);
                ans = max(ans, res);
            }
        return ans;
    }
};
// @lc code=end

