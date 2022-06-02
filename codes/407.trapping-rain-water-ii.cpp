/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        int surface[n][m];
        memset(surface, 127, sizeof(surface));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0, cur = 0; j < m; j++) {
                cur = max(cur, heightMap[i][j]);
                surface[i][j] = min(surface[i][j], cur);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = m - 1, cur = 0; j >= 0; j--) {
                cur = max(cur, heightMap[i][j]);
                surface[i][j] = min(surface[i][j], cur);
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0, cur = 0; i < n; i++) {
                cur = max(cur, heightMap[i][j]);
                surface[i][j] = min(surface[i][j], cur);
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = n - 1, cur = 0; i >= 0; i--) {
                cur = max(cur, heightMap[i][j]);
                surface[i][j] = min(surface[i][j], cur);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += surface[i][j] - heightMap[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

