/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
class Solution {
    int lower, upper;
    vector<long long> sum;
    int Merge(int l, int r) {
        if (l == r) return 0;
        int mid = (l + r) / 2;
        int res = Merge(l, mid) + Merge(mid + 1, r);
        for (int i = mid + 1, p = l, q = l; i <= r; i++) {
            while (p <= mid && sum[i] - sum[p] > upper) p++;
            while (q <= mid && sum[i] - sum[q] >= lower) q++;
            if (p < q) res += q - p;
        }
        vector<long long> sorted;
        int p = l, q = mid + 1;
        while (p <= mid || q <= r) {
            if (p > mid) sorted.push_back(sum[q++]);
            else if (q > r) sorted.push_back(sum[p++]);
            else if (sum[p] < sum[q]) sorted.push_back(sum[p++]);
            else sorted.push_back(sum[q++]);
        }
        for (int i = l; i <= r; i++) sum[i] = sorted[i - l];
        return res;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        this->lower = lower;
        this->upper = upper;
        int n = nums.size();
        sum = vector<long long>(n + 1);
        sum[0] = 0;
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
        return Merge(0, n);
    }
};
// @lc code=end

