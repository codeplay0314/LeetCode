/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> tnodes;
        queue<int> depths;
        tnodes.push(root);
        depths.push(0);
        int sum, d = -1;
        while (!tnodes.empty()) {
            TreeNode* node = tnodes.front();
            int dep = depths.front();
            tnodes.pop();
            depths.pop();
            if (d < dep) {
                d = dep;
                sum = 0;
            }
            sum += node->val;
            if (node->left) {
                tnodes.push(node->left);
                depths.push(dep + 1);
            }
            if (node->right) {
                tnodes.push(node->right);
                depths.push(dep + 1);
            }
        }
        return sum;
    }
};
// @lc code=end

