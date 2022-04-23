/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> pre(n, 0);
        for (int i = 1; i < n; i++)
            if (ratings[i - 1] < ratings[i]) pre[i]++;
            else if (ratings[i - 1] > ratings[i]) pre[i - 1]++;
        
        queue<int> q;
        vector<int> depth(n, 1);
        for (int i = 0; i < n; i++)
            if (!pre[i]) q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            vector<int> nxt;
            if (x && ratings[x] < ratings[x - 1]) nxt.push_back(x - 1);
            if (x < n - 1 && ratings[x] < ratings[x + 1]) nxt.push_back(x + 1);
            for (auto y : nxt) {
                pre[y]--;
                depth[y] = max(depth[y], depth[x] + 1);
                if (!pre[y]) q.push(y);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) ans += depth[i];
        return ans;
    }
};
// @lc code=end

