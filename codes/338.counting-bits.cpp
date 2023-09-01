/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i <<= 1) {
            for (int j = i, cur = 0; j <= n; j += i, cur ^= 1) {
                if (!cur) ans[j] += 1;
                else ans[j] -= 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};
// @lc code=end

