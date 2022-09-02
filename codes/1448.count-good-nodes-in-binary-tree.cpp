/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int DFS(TreeNode* u, int cur) {
        if (!u) return 0;
        int res = cur <= u->val;
        cur = max(cur, u->val);
        res += DFS(u->left, cur);
        res += DFS(u->right, cur);
        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return DFS(root, INT_MIN);
    }
};
// @lc code=end

