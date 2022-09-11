/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start
class Solution {
    const int mod = 1e9 + 7;
    class Engineer {
    public:
        int sp, ef;
        bool operator < (const Engineer& E) const {
            return ef > E.ef;
        }
    };
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Engineer> engs(n);
        for (int i = 0; i < n; i++) {
            engs[i].sp = speed[i];
            engs[i].ef = efficiency[i];
        }
        sort(engs.begin(), engs.end());

        long long ans = 0;
        long long tot_sp = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
            if (q.size() < k) {
                tot_sp += engs[i].sp;
                q.push(engs[i].sp);
            } else if (engs[i].sp > q.top()) {
                tot_sp += engs[i].sp - q.top();
                q.pop();
                q.push(engs[i].sp);
            }
            
            ans = max(ans, tot_sp * engs[i].ef);
        }
        return ans % mod;
    }
};
// @lc code=end

