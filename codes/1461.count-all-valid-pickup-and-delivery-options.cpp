/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
    bool exist[1<<20];
public:
    bool hasAllCodes(string s, int k) {
        int len = s.length(), tot = 1<<k;
        if (len < tot) return false;
        int sum = 0;
        for (int i = 0, cur = 0, lim = (tot>>1) - 1; i < len; i++) {
            cur &= lim;
            cur = (cur<<1) + (s[i] == '1');
            if (i >= k - 1) {
                if (!exist[cur]) sum++;
                exist[cur] = true;
            }
        }
        return sum == tot;
    }
};
// @lc code=end

