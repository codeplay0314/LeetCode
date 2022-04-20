/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
private:
    int nums;
    vector<int> xs, ys;
    int colban[9], rowban[9], cellban[3][3];
    
    vector<int> valid[9][9];
    void preProcess(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    xs.push_back(i);
                    ys.push_back(j);
                } else {
                    int digit = 1<<(board[i][j] - '1');
                    for (int k = 0; k < 9; k++) {
                        colban[i] |= digit;
                        rowban[j] |= digit;
                        cellban[i/3][j/3] |= digit;
                    }
                }
            }
        }
        nums = xs.size();
    }
     
    bool search(vector<vector<char>>& board, int num) {
        if (num == nums) return true;
        bool res = false;
        int x = xs[num], y = ys[num];
        int ban = colban[x] | rowban[y] | cellban[x/3][y/3];
        for (int i = 0; i < 9; i++) {
            if ((ban & (1<<i)) == 0) {
                board[x][y] = i + '1';
                colban[x] |= (1<<i);
                rowban[y] |= (1<<i);
                cellban[x/3][y/3] |= (1<<i);
                if (search(board, num + 1)) {
                    res = true;
                    break;
                }
                colban[x] ^= (1<<i);
                rowban[y] ^= (1<<i);
                cellban[x/3][y/3] ^= (1<<i);
            }
        }
        return res;
    }
    
public:
    Solution() {
        memset(colban, 0, sizeof(colban));
        memset(rowban, 0, sizeof(rowban));
        memset(cellban, 0, sizeof(cellban));
    }
    void solveSudoku(vector<vector<char>>& board) {
        preProcess(board);
        search(board, 0);
    }
};
// @lc code=end

