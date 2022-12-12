/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    pair<int, int> DFS(TreeNode* node) {
        if (!node) return make_pair(0, INT_MIN);
        pair<int, int> L = DFS(node->left), R = DFS(node->right);
        pair<int, int> res(max(L.first, R.first) + node->val, max(L.second, R.second));
        res.first = max(res.first, 0);
        res.second = max(res.second, L.first + R.first + node->val);
        return res;
    }
public:
    int maxPathSum(TreeNode* root) {
        return DFS(root).second;
    }
};
// @lc code=end

