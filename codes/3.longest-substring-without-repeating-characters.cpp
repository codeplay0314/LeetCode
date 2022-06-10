/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
    bool exist[256];
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int len = s.length();
        for (int i = 0, j = 0; i < len; i++) {
            while (j < len && !exist[s[j]]) {
                exist[s[j++]] = true;
            }
            ans = max(ans, j - i);
            exist[s[i]] = false;
        }
        return ans;
    }
};
// @lc code=end

