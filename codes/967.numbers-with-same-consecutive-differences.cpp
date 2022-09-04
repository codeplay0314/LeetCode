/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
    int _n, _k;
    vector<int> ans;
    void search(int t, int cur) {
        if (t == _n) {
            ans.push_back(cur);
            return;
        }
        if (!t) {
            for (int i = 1; i < 10; i++) {
                search(t + 1, i);
            }
        } else {
            int pre = cur % 10;
            if (_k) {
                if (pre - _k >= 0) search(t + 1, cur * 10 + pre - _k);
                if (pre + _k < 10) search(t + 1, cur * 10 + pre + _k);
            } else {
                search(t + 1, cur * 10 + pre);
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        _n = n;
        _k = k;
        search(0, 0);
        return ans;
    }
};
// @lc code=end

