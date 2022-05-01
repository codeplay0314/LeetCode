/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<char, int> prio;
    bool eval(string expr, int value) {
        expr += "$";
        stack<char> st;
        vector<long long> suff;
        int l = 0, r = 0;
        for (auto c : expr) {
            if (!isdigit(c)) {
                if (l < r) {
                    if (r - l > 1 && expr[l] == '0') return false;
                    suff.push_back(atoll(expr.substr(l, r - l).c_str()));
                    l = r + 1;
                }
                while (!st.empty() && prio[st.top()] >= prio[c]) {
                    char op = st.top();
                    if (op == '+') suff.push_back(-1);
                    else if (op == '-') suff.push_back(-2);
                    else if (op == '*') suff.push_back(-3);
                    st.pop();
                }
                st.push(c);
            }
            r++;
        }
        stack<long long> tokens;
        for (auto tk : suff) {
            if (tk >= 0) tokens.push(tk);
            else {
                long long y = tokens.top(); tokens.pop();
                long long x = tokens.top(); tokens.pop();
                if (tk == -1) tokens.push(x + y);
                else if (tk == -2) tokens.push(x - y);
                else tokens.push(x * y);
            }
        }
        return tokens.top() == value;
    }
    void preProcess() {
        prio['$'] = 0;
        prio['-'] = prio['+'] = 1;
        prio['*'] = 2;
    }
public:
    vector<string> addOperators(string num, int target) {
        preProcess();
        vector<string> ans;
        int n = num.length();
        for (int i = 0, possi = pow(4, n - 1); i < possi; i++) {
            string expr = {num[0]};
            for (int j = 1, p = i; j < n; j++) {
                if (p % 4 == 1) expr += "+";
                else if (p % 4 == 2) expr += "-";
                else if (p % 4 == 3) expr += "*";
                expr += num[j];
                p /= 4;
            }
            if (eval(expr, target)) ans.push_back(expr);
        }
        return ans;
    }
};
// @lc code=end

