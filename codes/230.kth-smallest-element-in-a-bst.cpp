/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int ans;
    
    int findKth(TreeNode* root, int k) {
        int lsize = root->left ? findKth(root->left, k) : 0;
        int rsize = root->right ? findKth(root->right, k - lsize - 1) : 0;
        if (k - lsize == 1) ans = root->val;
        return lsize + rsize + 1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        findKth(root, k);
        return ans;
    }
};
// @lc code=end

