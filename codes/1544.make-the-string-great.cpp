/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
    inline bool isnotgood(char c1, char c2) {
        return abs(c1 - c2) == 'a' - 'A';
    }
public:
    string makeGood(string s) {
        int len = s.length(), cur = 1;
        for (int i = 1; i < len; i++) {
            if (cur && isnotgood(s[i], s[cur - 1])) cur--;
            else s[cur++] = s[i];
        }
        return s.substr(0, cur);
    }
};
// @lc code=end

