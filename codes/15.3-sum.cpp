/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& ori) {
        sort(ori.begin(), ori.end());
        vector<int> nums{ori[0]};
        for (int i = 1, num = 1; i < ori.size(); i++) {
            if (ori[i] == ori[i - 1]) num++;
            else num = 1;
            if (num <= 3) nums.push_back(ori[i]);
        }
        set<vector<int>> res;
        map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) cnt[nums[i]]++;
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]--;
            for (int j = 0; j < i; j++) {
                if (cnt[-(nums[i] + nums[j])]) {
                    res.insert(vector<int>{nums[i], nums[j], -(nums[i] + nums[j])});    
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end

