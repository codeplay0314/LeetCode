/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
class Solution {
    int nums = 0;
    unordered_map<string, string> en, de;
    const string prefix = "http://tinyurl.com/";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (en.find(longUrl) != en.end()) return en[longUrl];
        en[longUrl] = prefix + to_string(nums);
        de[prefix + to_string(nums)] = longUrl;
        nums++;
        return en[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return de[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

