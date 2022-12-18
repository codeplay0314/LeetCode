/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= st.top().first) st.pop();
            if (!st.empty()) ans[i] = st.top().second - i;
            st.push(make_pair(temperatures[i], i));
        }
        return ans;
    }
};
// @lc code=end

