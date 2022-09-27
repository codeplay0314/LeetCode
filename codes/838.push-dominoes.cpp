/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution {
    void fill(string& str, int l, int r, char c) {
        for (int i = l; i < r; i++) str[i] = c;
    }
public:
    string pushDominoes(string dominoes) {
        int R = -1;
        for (int i = 0; i < dominoes.length(); i++) {
            if (dominoes[i] == 'R') {
                if (R >= 0) fill(dominoes, R + 1, i, 'R');
                R = i;
            }
            else if (dominoes[i] == 'L') {
                if (R < 0) {
                    int j = i - 1;
                    while (j >= 0 && dominoes[j] == '.') {
                        dominoes[j--] = 'L';
                    }
                } else {
                    fill(dominoes, R + 1, (i + R + 1) / 2, 'R');
                    fill(dominoes, (i + R) / 2 + 1, i, 'L');
                    R = -1;
                }
            }
        }
        if (R >= 0) fill(dominoes, R + 1, dominoes.length(), 'R');
        return dominoes;
    }
};
// @lc code=end

