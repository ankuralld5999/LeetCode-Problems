// Problem: https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(logN)
class Solution {
private:
  TreeNode *prev = NULL;
public:
  void flatten(TreeNode* root) {
    if (!root) return;
    TreeNode *right = root->right;
    if (prev) prev->right = root;
    root->right = root->left;
    root->left = NULL;
    prev = root;
    flatten(root->right);
    flatten(right);
  }
};
