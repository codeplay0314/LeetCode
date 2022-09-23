/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
    vector<string> ans;
    int p;
    string str;
    void search(int d, int l) {
        if (d == p) ans.push_back(str);
        else {
            if (2 * l < p) {
                str[d] = '(';
                search(d + 1, l + 1);
            }
            if (2 * l > d) {
                str[d] = ')';
                search(d + 1, l);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        p = 2 * n;
        str = string(p, '(');
        search(0, 0);
        return ans;
    }
};
// @lc code=end