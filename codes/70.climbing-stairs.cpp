/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int arr[3] = {1, 1, 1};
        for (int i = 2; i <= n; i++) {
            arr[2] = arr[0] + arr[1];
            arr[0] = arr[1];
            arr[1] = arr[2];
        }
        return arr[2];
    }
};
// @lc code=end

