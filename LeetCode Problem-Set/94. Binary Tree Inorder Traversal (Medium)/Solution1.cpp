// Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
private:
    vector<int> v;
    void inorder(TreeNode *root){
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return v;
    }
};
