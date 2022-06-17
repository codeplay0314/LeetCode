/*
 * @lc app=leetcode id=1050 lang=cpp
 *
 * [968] Binary Tree Cameras
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
    int DFS(TreeNode* u) {
        if (!u->left && !u->right) {
            return 0;
        }
        int res = 0;
        if (u->left) res = max(res, (DFS(u->left) + 2) % 3);
        if (u->right) res = max(res, (DFS(u->right) + 2) % 3);
        if (res == 2) ans++;
        return res;
    }
public:
    int minCameraCover(TreeNode* root) {
        return !DFS(root) + ans;
    }
};
// @lc code=end

