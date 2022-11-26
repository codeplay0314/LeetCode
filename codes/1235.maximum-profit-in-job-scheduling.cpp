/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
    class Interval {
    public:
        int st, ed, p;
        bool operator < (const Interval& I) const {
            return ed < I.ed;
        }
    };
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<int> head(n);
        vector<Interval> tail(n);
        for (int i = 0; i < n; i++) {
            head[i] = startTime[i];
            tail[i] = (Interval){startTime[i], endTime[i], profit[i]};
        }
        sort(head.begin(), head.end());
        sort(tail.begin(), tail.end());

        vector<pair<int, int>> dp = {make_pair(0, 0)};
        for (int h = 0, t = 0, pivot; h < n || t < n; ) {
            if (h >= n) pivot = tail[t].ed;
            else if (t >= n) pivot = head[h];
            else pivot = min(head[h], tail[t].ed);
            pair<int, int> res = make_pair(pivot, dp[dp.size() - 1].second);
            while (h < n && head[h] == pivot) {
                h++;
            }
            while (t < n && tail[t].ed == pivot) {
                int l = 0, r = dp.size() - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (dp[mid].first <= tail[t].st) l = mid + 1;
                    else r = mid - 1;
                }
                res.second = max(res.second, dp[r].second + tail[t].p);
                t++;
            }
            dp.push_back(res);
        }
        return dp[dp.size() - 1].second;
    }
};
// @lc code=end

