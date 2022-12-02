/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution {
    int num[2][26];
public:
    bool closeStrings(string word1, string word2) {
        int len = word1.length();
        if (word2.length() != len) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            num[0][word1[i] - 'a']++;
            num[1][word2[i] - 'a']++;
        }
        vector<int> t[2];
        for (int i = 0; i < 26; i++) {
            if (!!num[0][i] != !!num[1][i]) return false;
            if (num[0][i]) {
                t[0].push_back(num[0][i]);
                t[1].push_back(num[1][i]);
            }
        }
        sort(t[0].begin(), t[0].end());
        sort(t[1].begin(), t[1].end());
        for (int i = 0; i < t[0].size(); i++) {
            if (t[0] != t[1]) return false;
        }
        return true;
    }
};
// @lc code=end

