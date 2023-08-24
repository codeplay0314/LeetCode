/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
class Solution {
    inline int countSteps(int x, int n) {
        int res = 0;
        for (long i = x, j = x + 1; i <= n; i *= 10, j *= 10) {
            res += min(n + 1, (int)j) - i;
        }
        return res;
    }

public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        k--;
        while (k) {
            int steps = countSteps(ans, n);
            if (steps <= k) {
                k -= steps;
                ans++;
            } else {
                k--;
                ans *= 10;
            }
        }
        return ans;
    }
};
// @lc code=end

