/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
    class Node {
    public:
        int row, col, val;
        bool operator < (const Node& N) const {
            return col < N.col || (col == N.col && row < N.row) || (col == N.col && row == N.row && val < N.val);
        }
    };
    vector<Node> nodes;
    void DFS(TreeNode* u, int row, int col) {
        if (!u) return;
        nodes.push_back((Node){row, col, u->val});
        DFS(u->left, row + 1, col - 1);
        DFS(u->right, row + 1, col + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        DFS(root, 0, 0);
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        vector<int> column;
        for (int i = 0; i < nodes.size(); i++) {
            if (i && nodes[i].col != nodes[i - 1].col) {
                ans.push_back(column);
                column.clear();
            }
            column.push_back(nodes[i].val);
        }
        if (!column.empty()) {
            ans.push_back(column);
        }
        return ans;
    }
};
// @lc code=end

