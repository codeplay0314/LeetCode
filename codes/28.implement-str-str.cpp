/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        int nxt[m];
        memset(nxt, -1, sizeof(nxt));
        for (int i = 1, j = -1; i < m; i++) {
            while (j >= 0 && needle[i] != needle[j + 1]) j = nxt[j];
            if (needle[i] == needle[j + 1]) j++;
            nxt[i] = j;
        }
        int ans = -1;
        for (int i = 0, j = -1, sz = needle.size() - 1; i < n; i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) j = nxt[j];
            if (haystack[i] == needle[j + 1]) j++;
            if (j == sz) {
                ans = i - j;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

