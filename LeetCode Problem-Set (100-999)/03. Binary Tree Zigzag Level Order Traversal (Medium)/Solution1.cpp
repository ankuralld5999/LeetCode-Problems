// Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;
        vector<vector<int>> ans;
        while (q.size()) {
            int cnt = q.size();
            vector<int> lv;
            while (cnt--) {
                root = q.front();
                q.pop();
                lv.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (!l2r) reverse(begin(lv), end(lv));
            ans.push_back(lv);
            l2r = !l2r;
        }
        return ans;
    }
};
