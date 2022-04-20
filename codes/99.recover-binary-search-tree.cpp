/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    vector<TreeNode*> inorder;
    
    void inOrder(TreeNode* u) {
        if (u == NULL) return;
        inOrder(u->left);
        inorder.push_back(u);
        inOrder(u->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inOrder(root);
        
        TreeNode *u = NULL, *v = NULL;
        for (int i = 0, len = inorder.size(); i < len; i++) {
            bool invalid = false;
            if (i && inorder[i]->val < inorder[i - 1]->val) invalid = true;
            if (i < len - 1 && inorder[i]->val > inorder[i + 1]->val) invalid = true;
            if (invalid) {
                if (u == NULL) u = inorder[i];
                v = inorder[i];
            }
        }
        
        swap(u->val, v->val);
    }
};
// @lc code=end

