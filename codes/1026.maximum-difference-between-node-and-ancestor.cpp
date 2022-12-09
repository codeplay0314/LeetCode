/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
    int ans = 0;
    void DFS(TreeNode* node, int minnum, int maxnum) {
        if (!node) {
            ans = max(ans, maxnum - minnum);
        } else {
            if (minnum > node->val) minnum = node->val;
            if (maxnum < node->val) maxnum = node->val;
            DFS(node->left, minnum, maxnum);
            DFS(node->right, minnum, maxnum);
        }
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        DFS(root, INT_MAX, INT_MIN);
        return ans;
    }
};
// @lc code=end

