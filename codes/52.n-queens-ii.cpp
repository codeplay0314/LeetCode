/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
private:
    int n, ans = 0;
    long long colban = 0, p1ban = 0, p2ban = 0;
        
    int search(int x) {
        if (x == n) return 1;
        
        int res = 0;
        for (int y = 0; y < n; y++) {
            if (colban & (1<<y)) continue;
            if (p1ban & (1<<(x + y))) continue;
            if (p2ban & (1<<(x - y + n))) continue;
            colban ^= 1<<y;
            p1ban ^= 1<<(x + y);
            p2ban ^= 1<<(x - y + n);
            res += search(x + 1);
            colban ^= 1<<y;
            p1ban ^= 1<<(x + y);
            p2ban ^= 1<<(x - y + n);
        }
        return res;
    }
public:
    int totalNQueens(int len) {
        n = len;
        return search(0);
    }
};
// @lc code=end

