/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for (int oi = -n + 1; oi < n; oi++) {
            for (int oj = -n + 1; oj < n; oj++) {
                int res = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int i2 = i + oi, j2 = j + oj;
                        if (0 <= i2 && i2 < n && 0 <= j2 && j2 < n && (img1[i][j]&img2[i2][j2])) {
                            res++;
                        }
                    }
                }
                if (ans < res) {
                    ans = res;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

