/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
    inline int dis(int x, int y) {
        return x - y < 0 ? y - x : x - y;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            int k = n - 1;
            if (k == i + 1) k -= 2;
            for (int j = i + 1; j < n; j++) {
                if (j == k) k--;
                while (true) {
                    int nxtk = k - 1;
                    while (nxtk == i || nxtk == j) nxtk--;
                    if (nxtk < 0) break;
                    if (dis(nums[i] + nums[j] + nums[k], target) > dis(nums[i] + nums[j] + nums[nxtk], target)) {
                        k = nxtk;
                    } else break;
                }
                if (dis(ans, target) > dis(nums[i] + nums[j] + nums[k], target)) {
                    ans = nums[i] + nums[j] + nums[k];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

