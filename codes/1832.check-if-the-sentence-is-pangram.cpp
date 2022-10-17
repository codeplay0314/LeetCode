/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
    bool exist[26];
    int num = 0;
public:
    bool checkIfPangram(string sentence) {
        for (char c : sentence) {
            if (!exist[c - 'a']) {
                exist[c - 'a'] = true;
                if (++num == 26) return true;
            }
        }
        return false;
    }
};
// @lc code=end

