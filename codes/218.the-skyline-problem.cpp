/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
    class CheckPoint {
    public:
        int x, no;
        bool in;
    
        bool operator < (const CheckPoint& CP) const { return x < CP.x; }
        CheckPoint() {}
        CheckPoint(int _x, int _no, bool _in) : x(_x), no(_no), in(_in) {}
    };
    class Height {
    public:
        int h, no;

        bool operator < (const Height& H) const { return h < H.h; }
        Height(int _h, int _no) : h(_h), no(_no) {}
    };
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<CheckPoint> cps(2 * n, CheckPoint());
        for (int i = 0; i < n; i++) {
            int l = buildings[i][0], r = buildings[i][1];
            cps[i * 2] = CheckPoint(l, i, true);
            cps[i * 2 + 1] = CheckPoint(r, i, false);
        }
        sort(cps.begin(), cps.end());
        vector<int> in(n);
        priority_queue<Height> q;
        vector<vector<int>> ans;
        for (int i = 0, pre = -1; i < 2 * n; ) {
            int x = cps[i].x;
            while (i < 2 * n && cps[i].x == x) {
                CheckPoint cp = cps[i];
                if (cp.in) {
                    in[cp.no] = true;
                    q.push(Height(buildings[cp.no][2], cp.no));
                } else {
                    in[cp.no] = false;
                }
                i++;
            }
            while (!q.empty() && !in[q.top().no]) {
                q.pop();                
            }
            int cur = q.empty() ? 0 : q.top().h;
            if (pre != cur) {
                ans.push_back(vector<int>{x, cur});
                pre = cur;
            }
        }
        return ans;
    }
};
// @lc code=end

