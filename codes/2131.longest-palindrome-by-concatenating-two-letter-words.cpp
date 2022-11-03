/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int mid = 0;
        unordered_map<string, int> exist;
        for (string word : words) {
            string inv = (string){word[1], word[0]};
            if (exist[inv]) {
                ans += 4;
                exist[inv]--;
                if (word[0] == word[1]) mid--;
            } else {
                exist[word]++;
                if (word[0] == word[1]) mid++;
            }
        }
        if (mid) ans += 2;
        return ans;
    }
};
// @lc code=end

