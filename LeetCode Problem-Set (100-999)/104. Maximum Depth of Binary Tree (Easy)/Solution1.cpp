//Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxDepth(TreeNode* root) {
         if(root == NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};
