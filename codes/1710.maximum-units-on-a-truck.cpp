/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
bool cmp(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] > v2[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        for (vector<int> box : boxTypes) {
            int num = min(truckSize, box[0]);
            ans += num * box[1];
            truckSize -= num;
            if (!truckSize) break;
        }
        return ans;
    }
};
// @lc code=end

