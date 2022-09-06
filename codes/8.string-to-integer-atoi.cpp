/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int cur = 0;
        while (cur < s.length() && s[cur] == ' ') cur++;
        if (cur == s.length()) return 0;

        int sign = 1;
        if (s[cur] == '+') sign = 1, cur++;
        else if (s[cur] == '-') sign = -1, cur++;

        long long val = 0;
        while (cur < s.length() && isdigit(s[cur])) {
            val = val * 10 + s[cur] - '0';
            if (val >= INT_MAX) break;
            cur++;
        }
        val *= sign;

        val = max(val, (long long)INT_MIN);
        val = min(val, (long long)INT_MAX);
        
        return val;
    }
};
// @lc code=end

