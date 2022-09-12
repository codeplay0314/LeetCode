/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Sum of Even Numbers After Queries
 */

// @lc code=start
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0;
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size();
        while (l < r) {
            while (l < r && power >= tokens[l]) {
                power -= tokens[l];
                ans++;
                l++;
            }
            if (ans && l < r - 1) {
                power -= tokens[l] - tokens[r - 1];
                l++;
                r--;
            } else {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

