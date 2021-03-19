// OJ: https://leetcode.com/problems/recover-binary-search-tree/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
    TreeNode *a = NULL, *b = NULL;
    void update(TreeNode *x, TreeNode *y) {
        if (!a || x->val < a->val) a = x;
        if (!b || y->val > b->val) b = y;
    }
    void dfs(TreeNode *root, TreeNode *left = NULL, TreeNode *right = NULL) {
        if (!root) return;
        if (left && left->val > root->val) update(root, left);
        if (right && right->val < root->val) update(right, root);
        dfs(root->left, left, root);
        dfs(root->right, root, right);
    }
public:
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(a->val, b->val);
    }
};
