/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates in String

 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> res;
        for (char c : s) {
            if (!res.empty() && res.top() == c) res.pop();
            else res.push(c);
        }
        int len = res.size();
        char str[len + 1];
        str[len] = 0;
        for (int i = len - 1; i >= 0; i--) {
            str[i] = res.top();
            res.pop();
        }
        return string(str);
    }
};
// @lc code=end
