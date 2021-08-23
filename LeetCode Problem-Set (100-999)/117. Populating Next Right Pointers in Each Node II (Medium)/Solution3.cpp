// Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        auto first = root;
        while (first) {
            Node head, *tail = &head;
            for (auto node = first; node; node = node->next) {
                if (node->left) {
                    tail->next = node->left;
                    tail = tail->next;
                }
                if (node->right) {
                    tail->next = node->right;
                    tail = tail->next;
                }
            }
            first = head.next;
        }
        return root;
    }
};
