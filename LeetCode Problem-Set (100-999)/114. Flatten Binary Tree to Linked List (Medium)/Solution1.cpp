// Problem: https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(logN)
// Note: Left-to-right pre-order traversal has the reverse result of right-to-left post-order traversal.
class Solution {
private:
  TreeNode *prev = NULL;
public:
  void flatten(TreeNode* root) {
    if (!root) return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
  }
};
