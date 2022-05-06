/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II

 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int len = s.length();
        vector<int> rep(len, 1);
        vector<int> pre(len, 0);
        vector<int> rm(len, false);
        for (int i = 0, last = -1; i < s.length(); i++) {
            if (last >= 0 && s[i] == s[last]) {
                rep[i] = rep[last] + 1;
                pre[i] = last;
                last = i;
                if (rep[i] == k) {
                    int p = i;
                    for (int j = 0; j < k; j++) {
                        rm[p] = true;
                        p = pre[p];
                    }
                    last = p;
                }
            } else {
                pre[i] = last;
                last = i;
            }
        }
        string ans;
        for (int i = 0; i < len; i++) {
            if (!rm[i]) ans += s[i];
        }
        return ans;
    }
};
// @lc code=end
