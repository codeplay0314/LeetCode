/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
    inline int sign(int x) {
        if (!x) return 0;
        if (x > 0) return 1;
        return -1;
    }
public:
    int divide(int dividend, int divisor) {
        long long a = abs(dividend), b = abs(divisor);
        int s = sign(dividend) * sign(divisor);
        if (!s) return 0;
        long long ans = s * (long long)floor(exp(log(a) - log(b)) + 1e-10);
        if (ans < INT_MIN) ans = INT_MIN;
        if (ans > INT_MAX) ans = INT_MAX;
        return ans;
    }
};
// @lc code=end

