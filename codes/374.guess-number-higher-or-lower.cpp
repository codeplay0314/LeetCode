/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l>>1) + (r>>1) + (l&r&1);
            int res = guess(mid);
            if (res == 0) return mid;
            else if (res > 0) l = mid + 1;
            else r = mid - 1; 
        }
        return -1;
    }
};
// @lc code=end

