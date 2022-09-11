/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
    const vector<char> symbols = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    const vector<int> vals = {1, 5, 10, 50, 100, 500, 1000};
public:
    int romanToInt(string s) {
        map<char, int> val_mp;
        for (int i = 0; i < 7; i++) {
            val_mp[symbols[i]] = vals[i];
        }

        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += (i + 1 < s.length() && val_mp[s[i]] < val_mp[s[i + 1]] ? -1 : 1) * val_mp[s[i]];
        }
        return ans;
    }
};
// @lc code=end

