/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
    vector<string> split(string s) {
        vector<string> res;
        string cur = "";
        for (char c : s) {
            if (c == ' ') {
                if (cur.length() > 0) {
                    res.push_back(cur);
                    cur = "";
                }
            } else {
                cur += c;
            }
        }
        if (cur.length() > 0) {
            res.push_back(cur);
        }
        return res;
    }
public:
    string reverseWords(string s) {
        vector<string> words = split(s);
        string ans;
        for (int n = words.size(), i = n - 1; i >= 0; i--) {
            ans += i == n - 1 ? words[i] : " " + words[i];
        }
        return ans;
    }
};
// @lc code=end

