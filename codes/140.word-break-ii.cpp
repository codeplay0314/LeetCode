/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
    int n;
    string str;
    set<string> dic;
    void search(int t, string tmp, string& cur, vector<string>& ans) {
        if (t == n) {
            if (!tmp.size()) ans.push_back(cur.substr(1, cur.size() - 1));
            return;
        }
        tmp += str[t];
        search(t + 1, tmp, cur, ans);
        if (dic.count(tmp)) {
            cur += " " + tmp;
            search(t + 1, "", cur, ans);
            cur = cur.substr(0, cur.size() - tmp.size() - 1);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        str = s;
        for (auto word : wordDict) dic.insert(word);

        string cur;
        vector<string> ans;
        search(0, "", cur, ans);
        return ans;
    }
};
// @lc code=end

