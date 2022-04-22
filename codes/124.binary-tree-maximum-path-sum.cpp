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
    const static int inf = ~0u>>1;
    typedef pair<int, int> retV;
    retV dfs(TreeNode* u) {
        if (!u) return make_pair(0, -inf);
        retV lret = dfs(u->left);
        retV rret = dfs(u->right);
        
        retV ret = make_pair(u->val, u->val);
        ret.first = max(ret.first, u->val + lret.first);
        ret.first = max(ret.first, u->val + rret.first);
        ret.second += max(0, lret.first);
        ret.second += max(0, rret.first);
        ret.second = max(ret.second, lret.second);
        ret.second = max(ret.second, rret.second);

        return ret;
    }
public:
    int maxPathSum(TreeNode* root) {
        return dfs(root).second;
    }
};
// @lc code=end

