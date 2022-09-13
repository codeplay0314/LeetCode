/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
    bool digits[8];
    void GetDigits(int x) {
        for (int i = 0; i < 8; i++) {
            digits[i] = x&1;
            x >>= 1;
        }
    }
public:
    bool validUtf8(vector<int>& data) {
        int rest = 0;
        for (int i = 0; i < data.size(); i++) {
            GetDigits(data[i]);
            if (!rest) {
                if (!digits[7]) continue;
                if (!digits[6]) return false;
                if (!digits[5]) rest = 1;
                else if (!digits[4]) rest = 2;
                else if (!digits[3]) rest = 3;
                else return false;
            } else if (digits[7] && !digits[6]) {
                rest--;
            } else {
                return false;
            }
        }
        return !rest;
    }
};
// @lc code=end

