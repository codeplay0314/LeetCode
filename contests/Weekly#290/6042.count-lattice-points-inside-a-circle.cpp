class Solution {
    set<pair<int, int>> st;
    bool inCircle(vector<int> circle, int x, int y) {
        return (circle[0] - x) * (circle[0] - x) + (circle[1] - y) * (circle[1] - y) <= circle[2] * circle[2];
    }
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        for (auto cir : circles) {
            int x = cir[0], y = cir[1], r = cir[2];
            for (int i = x - r; i <= x + r; i++) {
                for (int d = 0; d <= r; d++) {
                    if (inCircle(cir, i, y - d)) {
                        st.insert(make_pair(i, y - d));
                        st.insert(make_pair(i, y + d));
                    }
                    else break;
                }
            }
        }
        return st.size();
    }
};