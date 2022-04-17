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
    class searchReturnValue {
    public:
        TreeNode *root, *last;
    };
    
    searchReturnValue search(TreeNode* node) {
        searchReturnValue lr, rr, res;
        
        if (node->left) {
            searchReturnValue lr = search(node->left);
            res.root = lr.root;
            lr.last->right = node;
            node->left = NULL;
        } else {
            res.root = node;
            node->left = NULL;
        }
        if (node->right) {
            searchReturnValue rr = search(node->right);
            node->right = rr.root;
            res.last = rr.last;
        } else {
            res.last = node;
        }
        
        return res;
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        searchReturnValue res = search(root);        
        return res.root;
    }
};