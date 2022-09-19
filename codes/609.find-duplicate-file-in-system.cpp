/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
    unordered_map<string, vector<string>> mp;
    vector<string> split(const string& str, char c) {
        vector<string> res;
        int cur = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == c && i > cur) {
                res.push_back(str.substr(cur, i - cur));
                cur = i + 1;
            }
        }
        if (str.length() > cur) res.push_back(str.substr(cur, str.length() - cur));
        return res;
    }
    void getFile(const string& str, string& file, string& cont) {
        for (int i = 0, l; i < str.length(); i++) {
            if (str[i] == '(') {
                file = str.substr(0, i);
                l = i + 1;
            } else if (str[i] == ')') {
                cont = str.substr(l, i - l);
            }
        }
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for (string path : paths) {
            vector<string> strs = split(path, ' ');
            string dir = strs[0];
            for (int i = 1; i < strs.size(); i++) {
                string file, cont;
                getFile(strs[i], file, cont);
                mp[cont].push_back(dir + "/" + file);
            }
        }

        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second.size() > 1) {
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};
// @lc code=end

