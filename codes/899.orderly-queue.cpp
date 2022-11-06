/*
 * @lc app=leetcode id=899 lang=cpp
 *
 * [899] Orderly Queue
 */

// @lc code=start
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        } else {
            string ans = s;
            for (int i = 0, len = s.length(); i < len; i++) {
                s = s.substr(1) + s[0];
                if (ans > s) ans = s;
            }
            return ans;
        }
    }
};
// @lc code=end

