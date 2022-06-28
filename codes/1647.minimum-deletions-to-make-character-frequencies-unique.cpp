/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
class Solution {
    int freq[27];
public:
    int minDeletions(string s) {
        for (char c : s) freq[c - 'a']++;
        sort(freq, freq + 27);
        int ans = 0;
        int pre = s.length() + 1, sum = 1;
        for (int i = 26; i >= 0; i--) {
            if (freq[i] == pre) {
                sum++;
            } else if (!pre) {
                break;
            } else {
                int a = min(sum, pre - freq[i]) - 1, b = max(0, sum - 1 - a);
                ans += a * (a + 1) / 2 + (a + 1) * b;
                sum = b + 1;
                pre = freq[i];
            }
        }
        return ans;
    }
};
// @lc code=end

