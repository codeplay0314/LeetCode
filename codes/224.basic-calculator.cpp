/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        vector<string> tokens;
        stack<char> ops;
        char pre_op = 0;
        int l = 0, r = 0, len = s.size();
        while (r < len) {
            if (!isdigit(s[r])) {
                if (r - l > 0) {
                    tokens.push_back(s.substr(l, r - l));
                    pre_op = ')';
                } else if (s[r] == '-' && pre_op != ')') {
                    tokens.push_back("0");
                }
                if (s[r] != ' ') {
                    if (s[r] != '(') {
                        while (!ops.empty()) {
                            char op = ops.top();
                            ops.pop();
                            if (op == '(') break;
                            else ops.push('(');
                            tokens.push_back(string{op});
                        }
                    }
                    if (s[r] != ')') {
                        ops.push(s[r]);
                    }
                    pre_op = s[r];
                }
                l = r + 1;
            }
            r++;
        }
        if (l < r) tokens.push_back(s.substr(l, r - l));
        while (!ops.empty()) {
            tokens.push_back(string{ops.top()});
            ops.pop();
        }

        stack<int> nums;
        for (string tk : tokens) {
            if (isdigit(tk[0])) nums.push(atoi(tk.c_str()));
            else {
                int y = nums.top(); nums.pop();
                int x = nums.top(); nums.pop();
                nums.push(tk == "+" ? x + y : x - y);
            }
        }
        return nums.top();
    }
};
// @lc code=end

