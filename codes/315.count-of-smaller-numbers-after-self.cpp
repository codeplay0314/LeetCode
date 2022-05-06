/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class SegmentTree {
public:
    void insert(int x) {
        _insert(0, x);
    }
    int find(int l, int r) {
        if (l >= r) return 0;
        return _find(0, l, r);
    }
    SegmentTree(int range) : _xs(range * 4, 0), _ls(range * 4), _ms(range * 4), _rs(range * 4) {
        init(0, range, 0);
    }
private:
    void _insert(int o, int x) {
        _xs[o]++;
        if (_ls[o] + 1 == _rs[o]) return;
        if (x < _ms[o]) _insert(o * 2 + 1, x);
        else _insert(o * 2 + 2, x);
    }
    int _find(int o, int l, int r) {
        // cout << o << " " << _ls[o] << " " << _rs[o] << " " << l << " " << r << endl;
        if (l <= _ls[o] && _rs[o] <= r) {
            return _xs[o];
        }
        int res = 0;
        if (l < _ms[o]) res += _find(o * 2 + 1, l, r);
        if (_ms[o] < r) res += _find(o * 2 + 2, l, r);
        return res;
    }
    void init(int l, int r, int o) {
        _ls[o] = l, _ms[o] = (l + r) / 2, _rs[o] = r;
        if (l + 1 == r) return;
        init(l, _ms[o], o * 2 + 1);
        init(_ms[o], r, o * 2 + 2);
    }
    vector<int> _xs;
    vector<int> _ls, _ms, _rs;
};

class Solution {
    const int maxnum = 1e4;
    const int range = 2 * maxnum + 1;
public:
    vector<int> countSmaller(vector<int>& nums) {
        SegmentTree st(range + 1);
        int n = nums.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            nums[i] += maxnum;
            ans[i] = st.find(0, nums[i]);
            st.insert(nums[i]);
        }
        return ans;
    }
};
// @lc code=end

