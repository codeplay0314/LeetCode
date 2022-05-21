/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start

const int inf = ~0u>>1;

class LIS {
public:
    int add(int x) {
        int l = 0, r = _len;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (_low[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        if (x < _low[l]) {
            if (_updates.find(l) == _updates.end() || _updates[l] > x) {
                _updates[l] = x;
            }
        }
        return l;
    }
    void apply_updates() {
        for (auto it = _updates.begin(); it != _updates.end(); it++) {
            _low[it->first] = it->second;
        }
        _updates.clear();
    }
    LIS(int len) : _len(len), _low(len + 1, inf) {
        _low[0] = 0;
    }
private:
    int _len;
    vector<int> _low;
    unordered_map<int, int> _updates;
};

bool cmp(vector<int>& A, vector<int>& B) {
    return A[0] < B[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int ans = 1;
        sort(envelopes.begin(), envelopes.end(), cmp);
        int size = envelopes.size();
        LIS lis(size);
        for (int i = 0, j = 0; i < size; i = j) {
            while (j < size && envelopes[i][0] == envelopes[j][0]) {
                ans = max(ans, lis.add(envelopes[j][1]));
                j++;
            }
            lis.apply_updates();
        }
        return ans;
    }
};
// @lc code=end

