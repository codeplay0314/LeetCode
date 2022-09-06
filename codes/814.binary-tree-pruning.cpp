/*
 * @lc app=leetcode id=814 lang=cpp
 *
 * [814] Binary Tree Pruning
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
    bool Removed(TreeNode* node) {
        if (!node) return true;
        bool removed = !node->val;
        bool res = Removed(node->left);
        if (res) node->left = NULL;
        removed &= res;
        res = Removed(node->right);
        if (res) node->right = NULL;
        removed &= res;
        return removed;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return Removed(root) ? NULL : root;
    }
};
// @lc code=end

