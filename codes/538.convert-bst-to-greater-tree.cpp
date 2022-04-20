/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
private:
    void dfs(TreeNode* u, int& add) {
        if (u == NULL) return;
        dfs(u->right, add);
        u->val += add;
        add = u->val;
        dfs(u->left, add);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int add = 0;
        dfs(root, add);
        return root;
    }
};
// @lc code=end

