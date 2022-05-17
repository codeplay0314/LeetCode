/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        static const int dim = 233;
        static const int mod = 1e9 + 7;
        int n = words.size();

        set<int> len_set;
        vector<int> lens(2 * n);
        for (int i = 0; i < n; i++) {
            lens[i] = lens[i + n] = words[i].length();
            len_set.insert(lens[i]);
            words.push_back(words[i]);
            reverse(words[i + n].begin(), words[i + n].end());
        }

        vector<vector<bool>> prePalin(2 * n);
        vector<vector<int>> preHash(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            int len = lens[i];

            // Manacher
            prePalin[i] = vector<bool>(len + 1, false);
            
            int slen = 2 * len + 1;
            string s(slen, '#');
            for (int j = 0; j < len; j++) {
                s[j * 2 + 1] = words[i][j];
            }
            vector<int> d(slen);
            for (int j = 0, l = 0, r = -1; j < slen; j++) {
                d[j] = j > r ? 1 : min(d[l + r - j], r - j + 1);
                while (j - d[j] >= 0 && j + d[j] < slen && s[j - d[j]] == s[j + d[j]]) d[j]++;
                if (j + d[j] - 1 > r) l = j - d[j] + 1, r = j + d[j] - 1;
                if (d[j] == j + 1) prePalin[i][(j + d[j]) / 2] = true;
            }

            // Hash
            preHash[i] = vector<int>(len + 1);
            preHash[i][0] = 0;
            for (int j = 1; j <= len; j++) {
                preHash[i][j] = ((long long)preHash[i][j - 1] * dim + words[i][j - 1]) % mod;
            }
        }

        vector<int> all_lens;
        map<pair<int, int>, vector<int>> mp;
        all_lens.assign(len_set.begin(), len_set.end());
        for (int i = n; i < 2 * n; i++) {
            for (int len : all_lens) {
                if (len > lens[i]) break;
                pair<int, int> feat = make_pair(len, preHash[i][len]);
                // mp[feat].push_back(i - n);
                if (mp.find(feat) == mp.end()) {
                    mp[feat] = vector<int>{i - n};
                } else {
                    mp[feat].push_back(i - n);
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int len : all_lens) {
                if (len > lens[i]) break;                
                pair<int, int> feat = make_pair(len, preHash[i][len]);
                vector<int>& matches = mp[feat];
                for (int j : matches) {
                    if (i == j || (len != lens[i] && len != lens[j])) continue;
                    int s = min(lens[i], lens[j]);
                    if (lens[i] < lens[j] ? prePalin[j][lens[j] - s] : prePalin[i + n][lens[i] - s]) {
                        ans.push_back(vector<int>{i, j});
                    }
                }
            }
        }

        return ans;
    }
};

// @lc code=end

