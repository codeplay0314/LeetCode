/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
    const char albet[4][2] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', '-'}};
public:
    string intToRoman(int num) {
        string ans;
        for (int i = 0; num; i++, num /= 10) {
            int x = num % 10;
            string res;
            if (x == 4) res = {albet[i][0], albet[i][1]};
            else if (x == 9) res = {albet[i][0], albet[i + 1][0]};
            else {
                if (x >= 5) res = albet[i][1], x -= 5;
                while (x--) res += albet[i][0];
            }
            ans = res + ans;
        }
        return ans;
    }
};
// @lc code=end

