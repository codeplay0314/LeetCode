/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
class Solution {
    inline bool isvowel(char c) {
        if ('A' <= c && c <= 'Z') c -= 'A' - 'a';
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    bool halvesAreAlike(string s) {
        int len = s.length();
        int num[2] = {0, 0};
        for (int i = 0; i < len / 2; i++) {
            if (isvowel(s[i])) num[0]++;
        }
        for (int i = len / 2; i < len; i++) {
            if (isvowel(s[i])) num[1]++;
        }
        return num[0] == num[1];
    }
};
// @lc code=end

