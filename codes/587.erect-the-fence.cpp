/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
inline bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
}

inline bool nonconv(const vector<int>& v1, const vector<int>& v2, const vector<int>& v3) {
    return (v2[1] - v1[1]) * (v3[0] - v2[0]) > (v3[1] - v2[1]) * (v2[0] - v1[0]);
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n == 1) return trees;

        sort(trees.begin(), trees.end(), cmp);

        vector<int> lower, upper;
        lower.push_back(0);
        lower.push_back(1);
        for (int i = 2; i < n; i++) {
            while (lower.size() > 1 && nonconv(trees[lower[lower.size() - 2]], trees[lower[lower.size() - 1]], trees[i])) lower.pop_back();
            lower.push_back(i);
        }
        upper.push_back(n - 1);
        upper.push_back(n - 2);
        for (int i = n - 3; i >= 0; i--) {
            while (upper.size() > 1 && nonconv(trees[upper[upper.size() - 2]], trees[upper[upper.size() - 1]], trees[i])) upper.pop_back();
            upper.push_back(i);
        }

        set<int> ansset;
        for (int p : lower) ansset.insert(p);
        for (int p : upper) ansset.insert(p);

        vector<vector<int>> ans;
        for (auto it = ansset.begin(); it != ansset.end(); it++) {
            ans.push_back(trees[*it]);
        }
        return ans;
    }
};
// @lc code=end

