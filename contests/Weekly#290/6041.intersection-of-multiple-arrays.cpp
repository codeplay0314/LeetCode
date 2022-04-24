class Solution {
    int sum[1001];
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> sum(1001, 0);
        for (auto list : nums) {
            for (auto num : list) {
                sum[num]++;
            }
        }
        vector<int> ans;
        for (int i = 1, size = nums.size(); i < 1001; i++)
            if (sum[i] == size)
                ans.push_back(i);
        return ans;
    }
};