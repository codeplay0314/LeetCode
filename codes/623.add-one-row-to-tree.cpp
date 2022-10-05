/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
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
    void insert(TreeNode* root, int val) {
        root->left = new TreeNode(val, root->left, NULL);
        root->right = new TreeNode(val, NULL, root->right);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, NULL);
        }
        queue<TreeNode*> q;
        queue<int> dq;
        q.push(root);
        dq.push(1);
        while (!q.empty()) {
            TreeNode* tnode = q.front();
            int d = dq.front();
            q.pop(), dq.pop();
            if (d >= depth) break;
            if (d + 1 == depth) insert(tnode, val);
            if (tnode->left) q.push(tnode->left), dq.push(d + 1);
            if (tnode->right) q.push(tnode->right), dq.push(d + 1);
        }
        return root;
    }
};
// @lc code=end

