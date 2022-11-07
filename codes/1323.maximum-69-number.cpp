/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        string s;
        bool first = true;
        while (num) {
            s = (string){(char)(num % 10 + '0')} + s;
            num /= 10;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }
        return atoi(s.c_str());
    }
};
// @lc code=end

