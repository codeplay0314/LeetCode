/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
    stack<long long> st;
public:
    int evalRPN(vector<string>& tokens) {
        for (string tk : tokens) {
            if (isdigit(tk[0]) || (tk[0] == '-' && tk.length() > 1)) st.push(atoi(tk.c_str()));
            else {
                long long y = st.top(); st.pop();
                long long x = st.top(); st.pop();
                if (tk == "+") st.push(x + y);
                else if (tk == "-") st.push(x - y);
                else if (tk == "*") st.push(x * y);
                else st.push(x / y);
            }
        }
        return st.top();
    }
};
// @lc code=end

