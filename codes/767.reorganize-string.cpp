/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
    priority_queue<pair<int, char>> pq;
public:
    string reorganizeString(string s) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c : s) {
            cnt[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                pq.push({cnt[i], i + 'a'});
            }
        }

        string ans = "";
        pair<int, char> prev = {0, '#'};
        while (!pq.empty()) {
            pair<int, char> cur = pq.top();
            pq.pop();
            ans += cur.second;
            cur.first--;
            if (prev.first > 0) {
                pq.push(prev);
            }
            prev = cur;
        }
        if (ans.size() != s.size()) {
            return "";
        }
        return ans;
    }
};
// @lc code=end

