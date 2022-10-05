/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    int targetSum;
    bool ans = false;
    void DFS(TreeNode* tnode, int cur) {
        cur += tnode->val;
        if (!ans && !tnode->left && !tnode->right) {
            ans = cur == targetSum;
        }
        if (tnode->left) DFS(tnode->left, cur);
        if (tnode->right) DFS(tnode->right, cur);
    }
public:
    bool hasPathSum(TreeNode* root, int _targetSum) {
        targetSum = _targetSum;
        if (root) DFS(root, 0);
        return ans;
    }
};
// @lc code=end

