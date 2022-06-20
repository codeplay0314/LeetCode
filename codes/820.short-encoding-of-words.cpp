/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
class Solution {
    static const int maxn = 2000;
    bool del[maxn];
    bool isSuffix(const string& s1, const string& s2) {
        int len = s1.length();
        if (s2.length() < len) return false;
        for (int i = 0, j = s2.length() - len; i < len; i++) {
            if (s1[i] != s2[j + i]) return false;
        }
        return true;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!del[i] && !del[j] && i != j) {
                    if (words[i] == words[j]) {
                        del[min(i, j)] = true;
                    } else if (isSuffix(words[i], words[j])) {
                        del[i] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!del[i]) ans += words[i].length() + 1;
        }
        return ans;
    }
};
// @lc code=end

