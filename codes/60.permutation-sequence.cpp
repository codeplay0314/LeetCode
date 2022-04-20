/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        int perNum = 1;
        bool used[n];
        memset(used, 0, sizeof(used));
        for (int i = 2; i < n; i++) perNum *= i;
        
        k--;
        for (int i = n - 1; i >= 0; i--) {
            int num = k / perNum + 1, x;
            for (int j = 0; j < n; j++) {
                if (!used[j] && --num == 0) {
                    x = j;
                    break;
                } 
            }
            used[x] = true;
            ans += x + '1';
            if (i) {
                k %= perNum;
                perNum /= i;
            }
        }
        return ans;
    }
};
// @lc code=end

