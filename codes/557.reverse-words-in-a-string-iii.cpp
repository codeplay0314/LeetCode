/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                for (int j = i - 1; j >= cur; j--) ans += s[j];
                ans += s[i];
                cur = i + 1;
            }
        }
        for (int j = s.length() - 1; j >= cur; j--) ans += s[j];
        return ans;
    }
};
// @lc code=end

