/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Word {
public:
    string word;
    int freq;
    Word(const string& _word, int _freq) : word(_word), freq(_freq) {}
    bool operator < (const Word& W) const {
        return freq > W.freq || (freq == W.freq && word < W.word);
    }
};
class Solution {
    unordered_map<string, int> freq;
    vector<Word> res;
    vector<string> ans;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (string word :words) {
            freq[word]++;
        }
        for (auto it = freq.begin(); it != freq.end(); it++) {
            res.push_back(Word(it->first, it->second));
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < k; i++) ans.push_back(res[i].word);
        return ans;
    }
};
// @lc code=end

