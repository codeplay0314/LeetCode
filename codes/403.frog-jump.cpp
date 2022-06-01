/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<set<long long>> reaches(n, set<long long>());
        if (stones[1] != 1) return false;
        reaches[1].insert(1);
        for (int i = 2; i < n; i++) {
            for (int j = 1; j < i; j++) {
                int step = stones[i] - stones[j];
                for (int k = step - 1; k <= step + 1; k++) {
                    if (reaches[j].find(k) != reaches[j].end()) {
                        reaches[i].insert(step);
                        break;
                    }
                    if (k == INT_MAX) break;
                }
            }
        }
        return !reaches[n - 1].empty();
    }
};
// @lc code=end

