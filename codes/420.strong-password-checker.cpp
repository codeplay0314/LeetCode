/*
 * @lc app=leetcode id=420 lang=cpp
 *
 * [420] Strong Password Checker
 */

// @lc code=start
class Solution {
public:
    int strongPasswordChecker(string password) {
        char last = 0;
        int cnt = 0;
        int ans = 0;
        bool lower = false, upper = false, digit = false;
        queue<int> rep[3];
        for (char c : password) {
            if (last != c) {
                last = c;
                if (cnt >= 3) {
                    rep[cnt % 3].push(cnt);
                }
                ans += cnt / 3;
                cnt = 1;
            } else {
                cnt++;
            }
            if ('a' <= c && c <= 'z') {
                lower = true;
            } else if ('A' <= c && c <= 'Z') {
                upper = true;
            } else if (isdigit(c)) {
                digit = true;
            }
        }
        if (cnt >= 3) {
            rep[cnt % 3].push(cnt);
        }
        ans += cnt / 3;

        if (password.size() > 20) {
            int del = password.size() - 20;
            while (del > 0 && !rep[0].empty()) {
                int t = rep[0].front();
                rep[0].pop();
                if (t - 1 >= 3) {
                    rep[2].push(t - 1);
                }
                ans -= 1;
                del -= 1;
            }
            while (del > 1 && !rep[1].empty()) {
                int t = rep[1].front();
                rep[1].pop();
                if (t - 2 >= 3) {
                    rep[2].push(t - 2);
                }
                ans -= 1;
                del -= 2;
            }
            while (del > 2 && !rep[2].empty()) {
                int t = rep[2].front();
                rep[2].pop();
                int res = min(del / 3, t / 3);
                ans -= res;
                del -= res * 3;
            }
            ans = max(ans, (!lower) + (!upper) + (!digit));
            ans += password.size() - 20;
        } else if (password.size() < 6) {
            ans = 6 - password.size();
            if (!rep[2].empty() && rep[2].front() == 5) {
                ans = 2;
            }
        }
        
        return ans;
    }
};
// @lc code=end
