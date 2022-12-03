/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
unordered_map<char, int> freq;
static bool cmp(const char& c1, const char& c2) {
    return freq[c1] > freq[c2] || (freq[c1] == freq[c2] && c1 < c2);
}

class Solution {
public:
    string frequencySort(string s) {
        freq.clear();
        for (char c : s) freq[c]++;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
// @lc code=end

