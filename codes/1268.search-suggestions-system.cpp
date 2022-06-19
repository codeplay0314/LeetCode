/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
class Solution {
    static const int maxn = 1000;
    int pos[maxn];
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        int n = products.size();
        int len = searchWord.length();
        sort(products.begin(), products.end());
        for (int i = 0; i < len; i++) {
            int ans[3], sum = 0;
            for (int j = 0; j < n; j++) {
                if (pos[j] < products[j].length() && pos[j] == i && products[j][pos[j]] == searchWord[i]) {
                    pos[j]++;
                   if (sum < 3) ans[sum++] = j;
                }
            }
            vector<string> tmp;
            for (int j = 0; j < sum; j++) {
                tmp.push_back(products[ans[j]]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
// @lc code=end

