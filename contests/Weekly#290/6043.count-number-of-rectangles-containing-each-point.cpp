class Solution {
    vector<int> lists[101];
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int Y = 0;
        for (auto rec : rectangles) {
            int x = rec[0], y = rec[1];
            lists[y].push_back(x);
            Y = max(Y, y);
        }
        for (int i = 1; i <= Y; i++) sort(lists[i].begin(), lists[i].end());
        vector<int> ans;
        for (auto p : points) {
            int res = 0;
            int x = p[0], y = p[1];
            for (int i = y; i <= Y; i++)
                res += lists[i].end() - lower_bound(lists[i].begin(), lists[i].end(), x);
            ans.push_back(res);
        }
        return ans;
    }
};