// Problem: https://leetcode.com/problems/balanced-binary-tree/
// Author: github.com/ankuralld5999
class Solution {
private:
    bool isBalanced(TreeNode* root, int &h) {
        h = 0;
        if (!root) return true;
        int L, R;
        bool b = isBalanced(root->left, L) && isBalanced(root->right, R) && abs(L - R) <= 1;
        h = 1 + max(L, R);
        return b;
    }
public:
    bool isBalanced(TreeNode* root) {
        int h;
        return isBalanced(root, h);
    }
};
