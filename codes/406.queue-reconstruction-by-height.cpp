/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
}
class Solution {
    vector<vector<int>> ans;
    void insert(vector<int> p) {
        ans.push_back(p);
        for (int i = ans.size() - 1; i > p[1]; i--) {
            ans[i] = ans[i - 1];
        }
        ans[p[1]] = p;
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        for (vector<int> p : people) {
            insert(p);
        }
        return ans;
    }
};
// @lc code=end

