// Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        auto first = root;
        while (first && first->left) {
            for (auto node = first; node; node = node->next) {
                node->left->next = node->right;
                if (node->next) node->right->next = node->next->left;
            } 
            first = first->left;
        }
        return root;
    }
};
