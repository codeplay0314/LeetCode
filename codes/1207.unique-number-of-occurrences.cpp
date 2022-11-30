/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
    static const int maxn = 1000;
    bool exist[maxn + 1];
    unordered_map<int, int> mp;
public:
    bool uniqueOccurrences(vector<int>& arr) {
        for (int num : arr) {
            mp[num]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int occ = it->second;
            if (exist[occ]) return false;
            exist[occ] = true;
        }
        return true;
    }
};
// @lc code=end

