/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
    int k, n;
    vector<int> cur;
    vector<vector<int>> ans;
    void search(int t, int sum) {
        if (t == k) {
            if (sum == n) ans.push_back(cur);
            return;
        }
        int begin = t ? cur[t - 1] : 0;
        for (int i = begin + 1; i < 10; i++) {
            if (10 - i >= k - t) {
                cur[t] = i;
                search(t + 1, sum + i);
            } 
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->n = n;
        cur = vector<int>(k);
        search(0, 0);
        return ans;
    }
};
// @lc code=end

