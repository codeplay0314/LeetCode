/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        deque<int> pos;
        for (int i = 0; i < n; i++) {
            while (!pos.empty() && pos.front() <= i - k) pos.pop_front();
            while (!pos.empty() && nums[pos.back()] <= nums[i]) pos.pop_back();
            pos.push_back(i);
            if (i - k + 1 >= 0) ans[i - k + 1] = nums[pos.front()];
        }
        return ans;
    }
};
// @lc code=end

