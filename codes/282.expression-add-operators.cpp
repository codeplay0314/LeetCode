/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
class Solution {
    int n;
    string nums;
    int target;
    vector<string> ans;
    void search(int p, const string& expr, long long cur, long long pre) {
        if (p == nums.size()) {
            if (cur == target) ans.push_back(expr);
            return;
        }
        string str;
        long long num = 0;
        for (int i = p; i < n; i++) {
            if (i > p && nums[p] == '0') break;
            str += nums[i];
            num = num * 10 + nums[i] - '0';
            if (p == 0) {
                search(i + 1, str, num, num);
            } else {
                search(i + 1, expr + "+" + str, cur + num, num);
                search(i + 1, expr + "-" + str, cur - num, -num);
                search(i + 1, expr + "*" + str, cur - pre + pre * num, pre * num);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        n = num.length();
        nums = num;
        this->target = target;
        search(0, "", 0, 0);
        return ans;
    }
};
// @lc code=end

