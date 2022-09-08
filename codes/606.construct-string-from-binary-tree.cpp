/*
 * @lc app=leetcode id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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
    string ans;
    void DFS(TreeNode* node) {
        if (!node) return;
        ans += "(" + to_string(node->val);
        if (node->right && !node->left) ans += "()";
        DFS(node->left);
        DFS(node->right);
        ans += ")";
    }
public:
    string tree2str(TreeNode* root) {
        DFS(root);
        return ans.substr(1, ans.length() - 2);
    }
};
// @lc code=end

