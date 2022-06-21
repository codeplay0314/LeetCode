/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// @lc code=start
class Solution {
    priority_queue<int> candidates;
    priority_queue<int, vector<int>, greater<int>> q;
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), cur;
        int sum = 0;
        for (cur = 1; cur < n; cur++) {
            int h = heights[cur] - heights[cur - 1];
            if (h > 0) {
                if (q.size() < ladders) {
                    q.push(h);
                } else if (ladders) {
                    candidates.push(h);
                    sum += h;
                    int x = q.top(), y = candidates.top();
                    if (x < y) {
                        q.pop();
                        q.push(y);
                        candidates.pop();
                        candidates.push(x);
                        sum += x - y;
                    }
                    if (sum > bricks) {
                        break;
                    }
                } else {
                    sum += h;
                    if (sum > bricks) {
                        break;
                    }
                }
            }
        }
        return cur - 1;
    }
};
// @lc code=end

