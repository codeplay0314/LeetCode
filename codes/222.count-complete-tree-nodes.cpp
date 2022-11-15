/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int GetHeight(TreeNode* node) {
        if (!node->right) return 0;
        return GetHeight(node->right) + 1;
    }
    int GetChild(TreeNode* node, int num, int h) {
        if (!h) {
            return !!node->left + !!node->right;
        }
        return GetChild(num&(1<<(h - 1)) ? node->right : node->left, num, h - 1);
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int h = GetHeight(root);
        int l = 0, r = (1<<h) - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int ch = GetChild(root, mid, h);
            if (ch) l = mid + 1;
            else r = mid - 1;
        }
        return (1<<(h + 1)) - 1 + (r >= 0 ? (r<<1) + GetChild(root, r, h) : 0);
    }
};
// @lc code=end

