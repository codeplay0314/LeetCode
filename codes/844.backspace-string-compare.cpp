/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Walking Robot Simulation
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st_s, st_t;
        for (auto c : s) {
            if (c == '#') {
                if (st_s.size()) st_s.pop();
            } else {
                st_s.push(c);
            }
        }
        for (auto c : t) {
            if (c == '#') {
                if (st_t.size()) st_t.pop();
            } else {
                st_t.push(c);
            }
        }
        int size = st_s.size();
        if (size != st_t.size()) return false;
        while (size--) {
            if (st_s.top() != st_t.top()) return false;
            st_s.pop(), st_t.pop();
        }
        return true;
    }
};
// @lc code=end

