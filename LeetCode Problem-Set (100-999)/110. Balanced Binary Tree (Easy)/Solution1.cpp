// Problem: https://leetcode.com/problems/balanced-binary-tree/
// Author: github.com/ankuralld5999
class Solution {
private:
    bool flag = true;
    int countHeight(TreeNode *root){
        if(!root)
            return 0;
        int left = countHeight(root->left);
        int right = countHeight(root->right);
        if(abs(left-right) > 1)
            flag = false;
        return max(left, right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;
        countHeight(root);
        return flag;
    }
};
