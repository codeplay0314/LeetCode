/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class SegmentTree {
public:
    void add(int l, int r, int x) {
        _add_l = l;
        _add_r = r;
        _add_x = x;
        _add(0, 0);
    }
    int get(int l, int r) {
        _get_l = l;
        _get_r = r;
        return _get(0, 0);
    }
    SegmentTree(int n, int* coor) : _tree(n * 4), _coor(coor) {
        _init(0, n, 0);
    }
private:
    void _init(int l, int r, int o) {
        int mid = (l + r) / 2;
        _tree[o].l = l;
        _tree[o].r = r;
        _tree[o].mid = mid;
        if (l + 1 == r) return;
        _init(l, mid, o * 2 + 1);
        _init(mid, r, o * 2 + 2);
    }

    void maintain(int o, int cur) {
        if (_tree[o].cover + cur > 0) {
            _tree[o].num = _coor[_tree[o].r] - _coor[_tree[o].l];
        } else if (_tree[o].l + 1 < _tree[o].r) {
            _tree[o].num = _tree[o * 2 + 1].num + _tree[o * 2 + 2].num;
        } else {
            _tree[o].num = 0;
        }
    }
    int _add_l, _add_r, _add_x;
    void _add(int o, int cur) {
        if (_add_l <= _tree[o].l && _tree[o].r <= _add_r) {
            _tree[o].cover += _add_x;
        } else {
            if (_add_l < _tree[o].mid) _add(o * 2 + 1, cur + _tree[o].cover);
            if (_tree[o].mid < _add_r) _add(o * 2 + 2, cur + _tree[o].cover);  
        }
        maintain(o, cur);
    }

    int _get_l, _get_r;
    int _get(int o, int cur) {
        if (_get_l <= _tree[o].l && _tree[o].r <= _get_r) {
            return _tree[o].num;
        }
        int res = 0;
        if (_add_l < _tree[o].mid) res += _get(o * 2 + 1, cur + _tree[o].cover);
        if (_tree[o].mid < _add_r) res += _get(o * 2 + 2, cur + _tree[o].cover);
        return res;
    }

    class Node {
    public:
        int l, r, mid;
        int cover = 0;
        int num = 0;
    };
    vector<Node> _tree;
    int* _coor;
};

class Seg {
public:
    int y, x1, x2, num;
};
inline bool cmp(Seg& S1, Seg& S2) {
    return S1.y < S2.y;
}

class Solution {
    static const int maxn = 2e4;
    static const int maxc = 1e5;
    int xs[2 * maxn];
    int x[2 * maxn], len = 0;
    unordered_map<int, int> proj;
    Seg segs[2 * maxn];
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        int minx = maxc, maxx = -maxc;
        int miny = maxc, maxy = -maxc;
        long long tot_area = 0;
        for (int i = 0; i < n; i++) {
            xs[i * 2] = rectangles[i][0];
            xs[i * 2 + 1] = rectangles[i][2];
            tot_area += (long long)(rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
            minx = min(minx, rectangles[i][0]);
            minx = min(minx, rectangles[i][2]);
            maxx = max(maxx, rectangles[i][0]);
            maxx = max(maxx, rectangles[i][2]);
            miny = min(miny, rectangles[i][1]);
            miny = min(miny, rectangles[i][3]);
            maxy = max(maxy, rectangles[i][1]);
            maxy = max(maxy, rectangles[i][3]);
        }
        if (tot_area != (long long)(maxx - minx) * (maxy - miny)) {
            return false;
        }
        sort(xs, xs + 2 * n);
        for (int i = 0; i < 2 * n; i++) {
            if (!len || xs[i] != x[len - 1]) {
                proj[xs[i]] = len;
                x[len++] = xs[i];
            }
        }
        
        for (int i = 0; i < n; i++) {
            segs[i * 2] = (Seg){rectangles[i][1], proj[rectangles[i][0]], proj[rectangles[i][2]], 1};
            segs[i * 2 + 1] = (Seg){rectangles[i][3], proj[rectangles[i][0]], proj[rectangles[i][2]], -1};
        }
        sort(segs, segs + 2 * n, cmp);
        SegmentTree stree(len, (int*)&x);
        long long area = 0;
        for (int i = 0, cover = 0, lasty = 0; i < 2 * n; ) {
            int y = segs[i].y;
            area += (long long)cover * (y - lasty);
            while (i < 2 * n && segs[i].y == y) {
                stree.add(segs[i].x1, segs[i].x2, segs[i].num);
                i++;
            }
            cover = stree.get(0, len);
            lasty = y;
        }

        return area == tot_area;
    }
};
// @lc code=end

