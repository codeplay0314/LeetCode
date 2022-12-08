/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    void lvs(TreeNode* node, vector<int>& seq) {
        if (!node->left && !node->right) {
            seq.push_back(node->val);
        } else {
            if (node->left) lvs(node->left, seq);
            if (node->right) lvs(node->right, seq);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq[2];
        lvs(root1, seq[0]);
        lvs(root2, seq[1]);
        int len = seq[0].size();
        if (len != seq[1].size()) return false;
        for (int i = 0; i < len; i++) {
            if (seq[0][i] != seq[1][i]) return false;
        }
        return true;
    }
};
// @lc code=end

