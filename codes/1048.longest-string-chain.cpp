/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */

// @lc code=start
class Solution {
    bool isPredecessor(const string& s1, const string& s2) {
        int len = s1.length();
        if (s2.length() != len + 1) return false;
        for (int i = 0, j = 0; i < len; i++, j++) {
            if (s1[i] != s2[j]) {
                if (i == j) i--;
                else return false;
            }
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> edges(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isPredecessor(words[i], words[j])) {
                    edges[i].push_back(j);
                }
            }
        }

        vector<int> dp(n, 1);
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j : edges[i]) {
                ind[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!ind[i]) q.push(i);
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : edges[i]) {
                dp[j] = max(dp[j], dp[i] + 1);
                if (!--ind[j]) q.push(j);
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

