// Problem: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
private:
  bool isValidBST(TreeNode *root, TreeNode *lb, TreeNode *rb) {
    if (!root) return true;
    if ((lb && root->val <= lb->val) || (rb && root->val >= rb->val)) return false;
    return isValidBST(root->left, lb, root) && isValidBST(root->right, root, rb);
  }
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
  }
};

// OR

// Problem: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode *left = NULL, TreeNode *right = NULL) {
        if (!root) return true;
        return (!left || root->val > left->val) && (!right || root->val < right->val) && isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
    }
};
