/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int len = s.length();
        vector<int> dp(len);
        set<string> words(dictionary.begin(), dictionary.end());
        for (int i = 0; i < len; i++) {
            if (words.find(s.substr(0, i + 1)) != words.end()) {
                dp[i] = 0;
                continue;
            }
            dp[i] = i + 1;
            for (int j = 0; j < i; j++) {
                dp[i] = min(dp[i], dp[j] + (words.find(s.substr(j + 1, i - j)) != words.end() ? 0 : i - j));
            }
        }
        return dp[len - 1];
    }
};
// @lc code=end

