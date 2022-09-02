/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<double> tot;
    vector<int> num;
    void DFS(TreeNode* node, int dep) {
        if (!node) return;
        while (dep > tot.size()) {
            tot.push_back(0);
            num.push_back(0);
        }
        tot += node->val;
        num += 1;
        DFS(node->left, dep + 1);
        DFS(node->right, dep + 1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        DFS(root, 1);
        for (int i = 0; i < tot.size(); i++) {
            tot[i] /= num[i];
        }
        return tot;
    }
};
// @lc code=end

