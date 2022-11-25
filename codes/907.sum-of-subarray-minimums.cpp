/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
    static const int mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;

        stack<int> st, pos;
        st.push(0);
        pos.push(-1);
        for (int i = 0, res = 0, n = arr.size(); i < n; i++) {
            while (arr[i] <= st.top()) {
                int tp = st.top(), ps = pos.top();
                st.pop();
                pos.pop();
                res = (res - (long long)tp * (ps - pos.top()) % mod + mod) % mod;
            }
            res = (res + (long long)arr[i] * (i - pos.top())) % mod;
            ans = (ans + res) % mod;
            st.push(arr[i]);
            pos.push(i);
        }
        return ans;
    }
};
// @lc code=end

