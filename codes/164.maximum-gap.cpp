/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int maxnum = 0;
        for (auto num : nums)
            if (maxnum < num) maxnum = num;
        int bsize = sqrt(maxnum) + 1;
        vector<vector<int>> bucket(bsize, vector<int>());
        for (auto num : nums) {
            bucket[num / bsize].push_back(num);
        }
        int ans = 0, pre = maxnum;
        for (int i = 0; i < bsize; i++) {
            int size = bucket[i].size();
            if (size) {
                sort(bucket[i].begin(), bucket[i].end());
                ans = max(ans, bucket[i][0] - pre);
                for (int j = 1; j < size; j++) ans = max(ans, bucket[i][j] - bucket[i][j - 1]);
                pre = bucket[i][size - 1];
            }
        }
        return ans;
    }
};
// @lc code=end

