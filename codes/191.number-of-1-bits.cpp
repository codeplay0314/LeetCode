/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
    inline uint32_t lowbit(uint32_t x) {
        return x & (~x + 1);
    }
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans++;
            n ^= lowbit(n);
        }
        return ans;
    }
};
// @lc code=end

