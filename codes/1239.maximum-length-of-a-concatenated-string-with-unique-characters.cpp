/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
    static const int maxn = 16;
    int size[maxn];
    bool conf[maxn][maxn];

    bool CheckConf(const string& str1, const string& str2) {
        bool ch[26];
        memset(ch, 0, sizeof(ch));
        for (char c : str1) {
            if (ch[c - 'a']) return true;
            ch[c - 'a'] = true;
        }
        if (str1 != str2) {
            for (char c : str2) {
                if (ch[c - 'a']) return true;
            }
        }
        return false;
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            size[i] = arr[i].size();
            for (int j = 0; j < i; j++) conf[i][j] = conf[j][i];
            for (int j = i; j < n; j++) conf[i][j] = CheckConf(arr[i], arr[j]);
        }

        int ans = 0;
        for (int k = 0; k < (1<<n); k++) {
            int sel[maxn], num = 0;
            bool confed = false;
            int res = 0;
            for (int i = 0, stat = k; !confed && i < n; i++, stat >>= 1) {
                if (stat&1) {
                    if (conf[i][i]) confed = true;
                    for (int j = 0; !confed && j < num; j++) {
                        if (conf[i][sel[j]]) {
                            confed = true;
                        }
                    }
                    sel[num++] = i;
                    res += size[i];
                }
            }
            if (!confed) {
                ans = max(ans, res);
            }
        }
        
        return ans;
    }
};
// @lc code=end

