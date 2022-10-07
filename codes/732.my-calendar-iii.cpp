/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
    vector<pair<int, bool>> bp;
    void add(vector<pair<int, bool>>& vec, pair<int, bool> p) {
        vec.push_back(p);
        for (int i = vec.size() - 2; i >= 0; i--) {
            if (vec[i].first > p.first) {
                vec[i + 1] = vec[i];
            } else {
                vec[i + 1] = p;
                break;
            }
            if (!i) vec[0] = p;
        }
    }
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        add(bp, make_pair(start, true));
        add(bp, make_pair(end, false));
        int ans = 0;
        for (int i = 0, j, res = 0; i < bp.size(); i = j) {
            j = i;
            while (j < bp.size() && bp[i].first == bp[j].first) {
                res += bp[j++].second ? 1 : -1;
                if (start == 1) {
                    cout << bp[j - 1].first << " " << bp[j - 1].second << " " << res << endl;
                }
            }
            ans = max(ans, res);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

