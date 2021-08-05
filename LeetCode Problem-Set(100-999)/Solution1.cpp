// Problem: https://leetcode.com/problems/same-tree/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (!p && !q) || (p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
