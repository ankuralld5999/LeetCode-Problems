// Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node head, *tail = &head;
        for (auto node = root; node; node = node->next) {
            if (node->left) {
                tail->next = node->left;
                tail = tail->next;
            }
            if (node->right) {
                tail->next = node->right;
                tail = tail->next;
            }
        }
        connect(head.next);
        return root;
    }
};
