//Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};
