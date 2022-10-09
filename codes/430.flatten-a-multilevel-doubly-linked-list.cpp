/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* DFS(Node* node, Node* prev) {
        if (!node) return prev;
        node->prev = prev;
        if (node->child) {
            Node* next = node->next;
            Node* childtail = DFS(node->child, node);
            node->next = node->child;
            node->child = nullptr;
            childtail->next = next;
            return DFS(next, childtail);
        } else {
            return DFS(node->next, node);
        }
    }
public:
    Node* flatten(Node* head) {
        DFS(head, nullptr);
        return head;
    }
};