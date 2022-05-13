/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    vector<Node*> last;
    void bfs(Node* u, int dep) {
        if (!u) return;
        if (dep >= last.size()) last.push_back(u);
        else {
            last[dep]->next = u;
            last[dep] = u;
        }
        bfs(u->left, dep + 1);
        bfs(u->right, dep + 1);
    }
public:
    Node* connect(Node* root) {
        bfs(root, 0);
        return root;
    }
};
// @lc code=end

