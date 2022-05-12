/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
    int n;
    vector<int> cur;
    unordered_map<int, int> sum;

    vector<vector<int>> ans;
    void search(int t) {
        if (t == n) {
            ans.push_back(cur);
            return;
        }
        for (unordered_map<int, int>::iterator it = sum.begin(); it != sum.end(); it++) {
            if (it->second) {
                cur[t] = it->first;
                it->second--;
                search(t + 1);
                it->second++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->n = nums.size();
        this->cur = vector<int>(n);
        for (int num : nums) sum[num]++;
        search(0);
        return ans;
    }
};
// @lc code=end

