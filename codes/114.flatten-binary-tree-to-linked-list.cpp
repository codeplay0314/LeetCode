/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    TreeNode* tail;
    void DFS(TreeNode* node) {
        if (!node) return;
        TreeNode *left = node->left, *right = node->right;
        tail->right = node;
        tail = node;
        tail->left = nullptr;
        DFS(left);
        DFS(right);
    }
public:
    void flatten(TreeNode* root) {
        tail = new TreeNode;
        DFS(root);
    }
};
// @lc code=end

