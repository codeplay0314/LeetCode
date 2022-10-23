/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
    static const int maxn = 1e4;
    int exist[maxn];
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int ans1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (exist[nums[i] - 1]) ans1 = nums[i];
            exist[nums[i] - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!exist[i]) {
                return vector<int>{ans1, i + 1};
            }
        }
        return vector<int>{};
    }
};
// @lc code=end

