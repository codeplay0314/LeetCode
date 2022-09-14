/*
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
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
    int ans;
    int nums[10];
    int odd;
    void DFS(TreeNode* node) {
        if (!node) return;
        odd += (++nums[node->val])&1 ? 1 : -1;
        DFS(node->left);
        DFS(node->right);
        if (!node->left && !node->right) ans += odd <= 1;
        odd += (--nums[node->val])&1 ? 1 : -1;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        DFS(root);
        return ans;
    }
};
// @lc code=end

