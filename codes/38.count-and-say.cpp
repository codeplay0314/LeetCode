/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int k = 1; k < n; k++) {
            char ch = 0;
            int num = 0;
            string res;
            for (char c : ans) {
                if (c == ch) num++;
                else {
                    if (ch) res += to_string(num) + (string){ch};
                    ch = c;
                    num = 1;
                }
            }
            ans = res + to_string(num) + (string){ch};
        }
        return ans;
    }
};
// @lc code=end

