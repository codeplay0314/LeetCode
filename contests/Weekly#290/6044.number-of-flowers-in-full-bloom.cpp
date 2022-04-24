class Solution {
    vector<int> st, ed;
    vector<int> times;
    unordered_map<int, int> ans;
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n = flowers.size();
        for (auto flower : flowers) {
            st.push_back(flower[0]);
            ed.push_back(flower[1] + 1);
        }
        for (auto person : persons) {
            times.push_back(person);
        }
        sort(st.begin(), st.end());
        sort(ed.begin(), ed.end());
        sort(times.begin(), times.end());
        int cur = 0, x = 0, y = 0;
        for (auto t : times) {
            while (x < n && st[x] <= t) x++, cur++;
            while (y < n && ed[y] <= t) y++, cur--;
            ans[t] = cur;
        }
        vector<int> res;
        for (auto person : persons) {
            res.push_back(ans[person]);
        }
        return res;
    }
};