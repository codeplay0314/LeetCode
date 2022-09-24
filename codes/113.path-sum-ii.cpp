/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> ans;
    vector<int> res;
    int target;
    void DFS(TreeNode* node, int cur) {
        if (!node) return;
        res.push_back(node->val);
        if (!node->left && !node->right) {
            if (cur + node->val == target) ans.push_back(res);
        } else {
            if (node->left) DFS(node->left, cur + node->val);
            if (node->right) DFS(node->right, cur + node->val);
        }
        res.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        DFS(root, 0);
        return ans;
    }
};
// @lc code=end

