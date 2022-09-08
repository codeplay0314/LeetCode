/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> ans;
    void DFS(TreeNode* node) {
        if (node->left) DFS(node->left);
        ans.push_back(node->val);
        if (node->right) DFS(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) DFS(root);
        return ans;
    }
};
// @lc code=end

