/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
class Solution {
    static const int maxn = 1000;
    unsigned bits[maxn];
public:
    int maxProduct(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                bits[i] |= 1 << (c - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if ((bits[i] & bits[j]) == 0) {
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

