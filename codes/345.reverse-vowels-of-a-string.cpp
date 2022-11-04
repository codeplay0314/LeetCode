/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
    inline bool isVowel(char c) {
        if ('A' <= c && c <= 'Z') c += 'a' - 'A';
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while (true) {
            while (l < n && !isVowel(s[l])) l++;
            while (r >= 0 && !isVowel(s[r])) r--;
            if (l >= r) break;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
// @lc code=end

