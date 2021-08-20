// Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        Node* leftnode = root;
        while(leftnode != NULL && leftnode->left != NULL){
            populate(leftnode);
            leftnode = leftnode->left;
        }
        return root;
    }
private:
    void populate(Node* startnode){
        Node* iter = startnode;
        while(iter != NULL){
            iter->left->next = iter->right;
            if(iter->next != NULL)
                iter->right->next = iter->next->left;
            iter = iter->next;
        }
    }
};
