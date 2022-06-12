/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution {
    static const int maxnum = 1e4;
    bool exist[maxnum + 1];
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, j = 0, n = nums.size(), sum = 0; i < n; i++) {
            while (j < n && !exist[nums[j]]) {
                exist[nums[j]] = true;
                sum += nums[j++];
            }
            ans = max(ans, sum);
            exist[nums[i]] = false;
            sum -= nums[i];
            
        }
        return ans;
    }
};
// @lc code=end

