/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
class Solution {
    unordered_map<string, bool> mp;
    bool sameCompose(string& s1, string& s2) {
        int sum[26];
        memset(sum, 0, sizeof(sum));
        for (auto c : s1) sum[c - 'a']++;
        for (auto c : s2) sum[c - 'a']--;
        for (int i = 0; i < 26; i++)
            if (sum[i]) return false;
        return true;
    }
public:
    bool isScramble(string s1, string s2) {
        string his = s1 + ";" + s2;
        if (mp.find(his) != mp.end()) return mp[his];

        int n = s1.size();
        if (n != s2.size()) return mp[his] = false;
        if (n == 1) return mp[his] = s1[0] == s2[0];
        if (s1 == s2) return mp[his] = true;
        if (!sameCompose(s1, s2)) return mp[his] = false;
        for (int i = 1; i < n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n), s2.substr(i, n))) return mp[his] = true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i, n)) && isScramble(s1.substr(i, n), s2.substr(0, n - i))) return mp[his] = true;
        }
        return mp[his] = false;
    }
};
// @lc code=end