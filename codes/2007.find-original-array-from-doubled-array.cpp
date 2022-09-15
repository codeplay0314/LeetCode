/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 */

// @lc code=start
class Solution {
    static const int maxc = 1e5;
    int cnt[maxc + 1];
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        sort(changed.begin(), changed.end());
        for (int i = changed.size() - 1; i >= 0; i--) {
            if (cnt[changed[i]]) {
                cnt[changed[i]]--;
                ans.push_back(changed[i]);
            } else if (changed[i] % 2) {
                return vector<int>();
            } else {
                cnt[changed[i] / 2]++;
            } 
        }
        return ans.size() * 2 == changed.size() ? ans : vector<int>();
    }
};
// @lc code=end

