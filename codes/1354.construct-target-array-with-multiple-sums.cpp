/*
 * @lc app=leetcode id=1354 lang=cpp
 *
 * [1354] Construct Target Array With Multiple Sums
 */

// @lc code=start
class Solution {
    priority_queue<int> q;
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }
        long long sum = 0;
        for (int num : target){
            q.push(num);
            sum += num;
        }
        while (true) {
            int x = q.top();
            if (x == 1) break;
            if (2 * x <= sum) return false;
            q.pop();
            int t = (x - q.top()) / (sum - x) + 1;
            int y = x - t * (sum - x);
            if (y < 1) {
                if (t == 1) return false;
                t--;
                y += sum - x;
            }
            q.push(y);
            sum += y - x;
        }
        return true;
    }
};
// @lc code=end

