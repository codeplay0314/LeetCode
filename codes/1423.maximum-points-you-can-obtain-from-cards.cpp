/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, ans = 0;
        for (int i = 0; i < k; i++) sum += cardPoints[i];
        ans = sum;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[n - i - 1] - cardPoints[k - i - 1];
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end

