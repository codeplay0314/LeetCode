/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q[2];
        q[0].push(original);
        q[1].push(cloned);
        while (!q[0].empty()) {
            TreeNode* u[2] = {q[0].front(), q[1].front()};
            q[0].pop(), q[1].pop();
            if (u[0]->val == target->val) return u[1];
            if (u[0]->left) q[0].push(u[0]->left), q[1].push(u[1]->left);
            if (u[0]->right) q[0].push(u[0]->right), q[1].push(u[1]->right);
        }
        return NULL;
    }
};
// @lc code=end

