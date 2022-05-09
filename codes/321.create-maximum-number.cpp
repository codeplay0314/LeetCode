/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans;
        for (int i = max(0, k - m); i <= n && i <= k; i++) {
            vector<int> list1 = findMax(nums1, i);
            vector<int> list2 = findMax(nums2, k - i);
            vector<int> res;
            int p = 0, q = 0;
            while (p < i || q < k - i) {
                if (less(list1, p, list2, q)) {
                    res.push_back(list2[q++]);
                } else {
                    res.push_back(list1[p++]);
                }
            }
            if (less(ans, 0, res, 0)) {
                ans = res;
            }
        }
        return ans;
    }
private:
    vector<int> findMax(vector<int>& list, int t) {
        vector<int> ans(t);
        for (int i = 0, cur = 0, n = list.size(); i < n; i++) {
            while (n - i + cur > t) {
                if (!cur || ans[cur - 1] >= list[i]) break;
                cur--;
            }
            if (cur < t) ans[cur++] = list[i];
        }
        return ans;
    }
    bool less(vector<int>& list1, int p, vector<int>& list2, int q) {
        int n = list1.size(), m = list2.size();
        while (p < n && q < m && list1[p] == list2[q]) {
            p++, q++;
        }
        return p == n || (q != m && list1[p] < list2[q]);
    }
};
// @lc code=end

