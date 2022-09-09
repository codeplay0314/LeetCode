/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 */

// @lc code=start
bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        stack<int> def;
        for (vector<int> prop : properties) {
            int d = prop[1];
            while (!def.empty() && def.top() < d) def.pop();
            def.push(d);
        }
        return properties.size() - def.size();
    }
};
// @lc code=end

