/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
    bool check(const string& g1, const string& g2) {
        int dif = 0;
        for (int i = 0; i < 8; i++) {
            if (g1[i] != g2[i]) {
                dif++;
            }
        }
        return dif == 1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int len = bank.size();
        vector<int> step(len, 0);
        queue<pair<string, int>> q;
        q.push(make_pair(start, 0));
        while (!q.empty()) {
            auto gene = q.front();
            q.pop();
            if (gene.first == end) return gene.second;
            for (int i = 0; i < len; i++) {
                if (step[i] == 0 && check(gene.first, bank[i])) {
                    step[i] = gene.second + 1;
                    q.push(make_pair(bank[i], step[i]));
                }
            }
        }
        return -1;
    }
};
// @lc code=end

