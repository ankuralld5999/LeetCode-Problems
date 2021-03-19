// OJ: https://leetcode.com/problems/recover-binary-search-tree/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
private:
    TreeNode *first = NULL, *second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void inorder(TreeNode *root){
        if(root==NULL)
            return;
        inorder(root->left);
        if(first==NULL && prev->val > root->val)
            first = prev;
        if(first!=NULL && prev->val > root->val)
            second = root;
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};
