/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
class Solution {
    inline int area(int x, int y) {
        return x * y;
    }
    int intersection(int a1, int a2, int b1, int b2) {
        if (a1 < b1) {
            if (b1 <= a2) return min(a2, b2) - b1;
            else return 0;
        } else {
            if (a1 <= b2) return min(a2, b2) - a1;
            else return 0;
        }
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        return area(ax2 - ax1, ay2 - ay1) + area(bx2 - bx1, by2 - by1) - area(intersection(ax1, ax2, bx1, bx2), intersection(ay1, ay2, by1, by2));
    }
};
// @lc code=end

