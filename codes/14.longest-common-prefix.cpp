/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            len = min(len, (int)strs[i].size());
            for (int j = 0; j < len; j++) {
                if (strs[i - 1][j] != strs[i][j]) {
                    len = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, len);
    }
};
// @lc code=end

