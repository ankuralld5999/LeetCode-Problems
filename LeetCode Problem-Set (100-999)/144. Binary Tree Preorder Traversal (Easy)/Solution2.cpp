// Problem: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (s.size()) {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return ans;
    }
};
