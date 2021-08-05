// Problem: https://leetcode.com/problems/same-tree/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(p==NULL || q==NULL || (p->val != q->val))
            return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
