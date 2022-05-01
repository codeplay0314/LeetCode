/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution {
    unordered_map<int, string> mp;
    void preProcess() {
        mp[1] = "One";
        mp[2] = "Two";
        mp[3] = "Three";
        mp[4] = "Four";
        mp[5] = "Five";
        mp[6] = "Six";
        mp[7] = "Seven";
        mp[8] = "Eight";
        mp[9] = "Nine";
        mp[10] = "Ten";
        mp[11] = "Eleven";
        mp[12] = "Twelve";
        mp[13] = "Thirteen";
        mp[14] = "Fourteen";
        mp[15] = "Fifteen";
        mp[16] = "Sixteen";
        mp[17] = "Seventeen";
        mp[18] = "Eighteen";
        mp[19] = "Nineteen";
        mp[20] = "Twenty";
        mp[30] = "Thirty";
        mp[40] = "Forty";
        mp[50] = "Fifty";
        mp[60] = "Sixty";
        mp[70] = "Seventy";
        mp[80] = "Eighty";
        mp[90] = "Ninety";
        mp[100] = "Hundred";
        mp[1000] = "Thousand";
        mp[1000000] = "Million";
        mp[1000000000] = "Billion";
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        preProcess();

        string ans;
        for (int i = 1000000000; i; i /= 1000) {
            int x = num / i % 1000;
            if (x) {
                if (x / 100) ans += mp[x / 100] + " " + mp[100] + " ";
                x %= 100;
                if (x) {
                    if (x < 20 || x % 10 == 0) ans += mp[x] + " ";
                    else ans += mp[x / 10 * 10] + " " + mp[x % 10] + " ";
                }
                if (i > 1) ans += mp[i] + " ";
            }
        }
        return ans.substr(0, ans.size() - 1);
    }
};
// @lc code=end

