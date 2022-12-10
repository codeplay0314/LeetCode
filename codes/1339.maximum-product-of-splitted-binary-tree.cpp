/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
    int sum;
    int sumup(TreeNode* node) {
        int res = node->val;
        if (node->left) res += sumup(node->left);
        if (node->right) res += sumup(node->right);
        return res;
    }
    static const int mod = 1e9 + 7;
    long long ans = 0;
    int split(TreeNode* node) {        
        int res = node->val, left = 0, right = 0;
        if (node->left) {
            left = split(node->left);
            ans = max(ans, (long long)left * (sum - left));
        }
        if (node->right) {
            right = split(node->right);
            ans = max(ans, (long long)right * (sum - right));
        }
        return res + left + right;
    }
public:
    int maxProduct(TreeNode* root) {
        sum = sumup(root);
        split(root);
        return ans % mod;
    }
};
// @lc code=end

