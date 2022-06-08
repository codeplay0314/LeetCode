/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
    int removePalindromeSub(string s) {
        int len = s.length();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - i - 1]) {
                return 2;
            }
        }
        return 1;
    }
};
// @lc code=end

