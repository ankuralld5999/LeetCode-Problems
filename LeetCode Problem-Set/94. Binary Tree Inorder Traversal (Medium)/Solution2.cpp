// Problem: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (root || s.size()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
