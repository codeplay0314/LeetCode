/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0, cur = 0, ones = 0, exp10 = 1;
        while (n) {
            int digit = n % 10;
            if (digit == 1) ans += ones + cur + 1;
            else if (digit > 1) ans += digit * ones + exp10;
            ones = ones * 10 + exp10;
            cur += digit * exp10;
            exp10 *= 10;
            n /= 10;
        }
        return ans;
    }
};
// @lc code=end

