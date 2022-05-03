/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string DFS(TreeNode* u, bool isr, int fa, int& num) {
        if (!u) return "";
        int cur = ++num;
        string res = ";" + to_string(fa) + "," + to_string(isr) + "," + to_string(u->val);
        res += DFS(u->left, false, cur, num);
        res += DFS(u->right, true, cur, num);
        return res;
    }
    vector<vector<int>> split(const string& data) {
        vector<string> nodes;
        for (int l = 0, r = 0; l < data.length(); r++) {
            if (data[r] == ';') {
                nodes.push_back(data.substr(l, r - l) + ",");
                l = r + 1;
            }
        } 
        vector<vector<int>> res;
        for (string node : nodes) {
            vector<int> tmp;
            for (int l = 0, r = 0; l < node.length(); r++) {
                if (node[r] == ',') {
                    tmp.push_back(atoi(node.substr(l, r - l).c_str()));
                    l = r + 1;
                }
            } 
            res.push_back(tmp);
        }
        return res;
    } 
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        int num = 0;
        string res = DFS(root, false, 0, num);
        return to_string(num) + res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<vector<int>> strs = split(data + ";");
        int n = strs[0][0];
        if (n == 0) return NULL;
        TreeNode** tnodes = new TreeNode*[n];
        for (int i = 0; i < n; i++) {
            tnodes[i] = new TreeNode;
            int fa = strs[i + 1][0] - 1;
            if (fa >= 0) {
                if (strs[i + 1][1]) tnodes[fa]->right = tnodes[i];
                else tnodes[fa]->left = tnodes[i];
            }
            tnodes[i]->val = strs[i + 1][2];
        }
        return tnodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

