/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];
}
class Solution {
    priority_queue<int> q;
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        int ans = 0, t = 0;
        for (auto course : courses) {
            if (course[1] - course[0] >= t) {
                ans++;
                t += course[0];
                q.push(course[0]);
            } else if (!q.empty() && course[0] < q.top()) {
                t += course[0] - q.top();
                q.pop();
                q.push(course[0]);
            }
        }
        return ans;
    }
};
// @lc code=end

