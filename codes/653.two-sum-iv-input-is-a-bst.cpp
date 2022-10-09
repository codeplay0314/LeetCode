/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> nums;
    void DFS(TreeNode* node) {
        if (!node) return;
        DFS(node->left);
        nums.emplace_back(node->val);
        DFS(node->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        DFS(root);
        int n = nums.size();
        for (int i = 0, j = n - 1; i < n; i++) {
            while (i < j && nums[i] + nums[j] > k) j--;
            if (i < j && nums[i] + nums[j] == k) return true;
        }
        return false;
    }
};
// @lc code=end

