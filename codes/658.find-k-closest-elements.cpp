/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
    class Num {
    public:
        int val, dis;
        bool operator < (const Num& N) const {
            return dis < N.dis || (dis == N.dis && val < N.val);
        };
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        Num nums[n];
        for (int i = 0; i < n; i++) nums[i] = (Num){arr[i], abs(arr[i] - x)};
        sort(nums, nums + n);
        vector<int> ans(k);
        for (int i = 0; i < k; i++) ans[i] = nums[i].val;
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

