/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
    inline bool check(vector<char>& vec) {
        sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i - 1] == vec[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> tmp;
        for (int i = 0; i < 9; i++) {
            tmp.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    tmp.push_back(board[i][j]);
                }
            }
            if (!check(tmp)) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            tmp.clear();
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    tmp.push_back(board[i][j]);
                }
            }
            if (!check(tmp)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                tmp.clear();
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        if (board[i + ii][j + jj] != '.') {
                            tmp.push_back(board[i + ii][j + jj]);
                        }
                    }
                }
                if (!check(tmp)) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

