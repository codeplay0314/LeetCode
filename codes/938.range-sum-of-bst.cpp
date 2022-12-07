/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int low, high;
    int sum;
    void count(TreeNode* node) {
        if (low <= node->val && node->val <= high) sum += node->val;
        if (node->left) count(node->left);
        if (node->right) count(node->right);
    }
public:
    int rangeSumBST(TreeNode* root, int _low, int _high) {
        low = _low;
        high = _high;
        count(root);
        return sum;
    }
};
// @lc code=end

