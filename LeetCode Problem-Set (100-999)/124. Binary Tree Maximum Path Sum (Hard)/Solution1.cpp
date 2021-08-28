// Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
private:
    int ans = INT_MIN;
    int postOrder(TreeNode *root) {
        if (!root) 
            return INT_MIN;
        int L = max(0, postOrder(root->left));
        int R = max(0, postOrder(root->right));
        ans = max(ans, L + R + root->val);
        return root->val + max(L, R);
    }
public:
    int maxPathSum(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};
