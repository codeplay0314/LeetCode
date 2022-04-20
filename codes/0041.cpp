class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (1 <= nums[i] && nums[i] <= n && i > nums[i] - 1) {
                if (nums[i] == nums[nums[i] - 1]) break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans = i + 1;
                break;
            }
            if (i == n - 1) ans = n + 1;
        }
        return ans;
    }
};