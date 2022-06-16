/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
    static const int maxn = 1000;
    int rad[maxn * 2 + 1];
    string Manacher(const string& str) {
        int n = str.length() * 2 + 1;
        string s(n, '#');
        for (int i = 1; i < n; i += 2) s[i] = str[i / 2];
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            rad[i] = r > i ? min(r - i, rad[l + r - i]) : 1;
            while (i - rad[i] >= 0 && i + rad[i] < n && s[i - rad[i]] == s[i + rad[i]]) rad[i]++;
            if (i + rad[i] > r) r = i + rad[i], l = i - rad[i];
        }
        int res = -1, pos;
        for (int i = 0; i < n; i++) {
            if (res < rad[i] - 1) {
                res = rad[i] - 1;
                pos = i;
            }
        }
        return str.substr((pos - rad[pos] + 1) / 2, res);
    }
public:
    string longestPalindrome(string s) {
        return Manacher(s);
    }
};
// @lc code=end

