// Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        q.push_front(root);
        bool l2r = true;
        while (q.size()) {
            int cnt = q.size();
            ans.emplace_back();
            while (cnt--) {
                if (l2r) {
                    root = q.front();
                    q.pop_front();
                } else {
                    root = q.back();
                    q.pop_back();
                }
                ans.back().push_back(root->val);
                if (l2r) {
                    if (root->left) q.push_back(root->left);
                    if (root->right) q.push_back(root->right);
                } else {
                    if (root->right) q.push_front(root->right);
                    if (root->left) q.push_front(root->left);
                }
            }
            l2r = !l2r;
        }
        return ans;
    }
};
