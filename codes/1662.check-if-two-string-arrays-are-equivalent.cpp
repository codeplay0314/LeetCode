/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Sum of Beauty of All Substrings
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for (string str : word1) str1 += str;
        for (string str : word2) str2 += str;
        return str1 == str2;
    }
};
// @lc code=end

