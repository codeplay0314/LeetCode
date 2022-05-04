/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
    vector<vector<bool>> res;
    vector<bool> removed;
    string pare;
    int n;
    void search(int t, int k, int st) {
        if (t == n && st == 0) {
            res.push_back(removed);
            return;
        }
        if (n - t - 1 >= k) {
            if (pare[t] == '(') {
                if (n - t - 1 >= st + 1) search(t + 1, k, st + 1);
            }
            else if (st > 0) search(t + 1, k, st - 1);
        }
        if (k) {
            removed[t] = true;
            search(t + 1, k - 1, st);
            removed[t] = false;
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;

        for (int i = 0; i < s.length(); i++) {
            if (!isalpha(s[i])) pare += s[i];
        }
        n = pare.length();

        removed = vector<bool>(n, false);
        for (int i = 0; i <= n; i++) {
            search(0, i, 0);
            if (!res.empty()) {
                for (vector<bool> rm : res) {
                    string tmp;
                    for (int j = 0, cnt = 0; j < s.length(); j++) {
                        if (!isalpha(s[j])) {
                            if (!rm[cnt]) tmp += s[j];
                            cnt++;
                        } else {
                            tmp += s[j];
                        }
                    }
                    bool repeated = false;
                    for (auto str : ans) {
                        if (str == tmp) {
                            repeated = true;
                            break;
                        }
                    }
                    if (!repeated) ans.push_back(tmp);
                }
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

