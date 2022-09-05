/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    vector<vector<int>> ans;
    void DFS(Node* u, int lev) {
        if (!u) return;
        while (ans.size() <= lev) ans.push_back(vector<int>());
        ans[lev].push_back(u->val);
        for (auto child : u->children) {
            DFS(child, lev + 1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        DFS(root, 0);
        return ans;
    }
};
// @lc code=end

