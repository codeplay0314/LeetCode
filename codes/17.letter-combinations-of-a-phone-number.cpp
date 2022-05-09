/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
    unordered_map<int, string> mp;
    string digits;
    vector<string> ans;
    void preprocess() {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
    }
    void search(int t, const string& cur) {
        if (t == digits.length()) {
            ans.push_back(cur);
            return;
        }
        for (char c : mp[digits[t] - '0']) {
            search(t + 1, cur + string{c});
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return ans;
        this->digits = digits;
        preprocess();
        search(0, "");
        return ans;
    }
};
// @lc code=end

