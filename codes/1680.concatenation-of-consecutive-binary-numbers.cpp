/*
 * @lc app=leetcode id=1680 lang=cpp
 *
 * [1680] Concatenation of Consecutive Binary Numbers
 */

// @lc code=start
class Solution {
    const int mod = 1e9 + 7;
    int pow2[22] = {1};
    inline int digit(int x) {
        int res = 0;
        while (x) {
            res++;
            x /= 2;
        }
        return res;
    }
public:
    int concatenatedBinary(int n) {
        for (int i = 1; i < 22; i++) pow2[i] = pow2[i - 1] * 2 % mod;
        int ans = 0;
        for (int i = n, cur = 1; i >= 1; i--) {
            ans = ((long long)i * cur + ans) % mod;
            cur = (long long)cur * pow2[digit(i)] % mod;
        }
        return ans;
    }
};
// @lc code=end

