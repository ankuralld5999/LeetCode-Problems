// Problem: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (root || s.size()) {
            if (!root) {
                root = s.top();
                s.pop();
            }
            ans.push_back(root->val);
            if (root->right) s.push(root->right);
            root = root->left;
        }
        return ans;
    }
};
