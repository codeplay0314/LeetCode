/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else if (st.empty()) return false;
            else if (c == ')') {
                if (st.top() != '(') return false;
                else st.pop();
            } else if (c == '}') {
                if (st.top() != '{') return false;
                else st.pop();
            } else if (c == ']') {
                if (st.top() != '[') return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

