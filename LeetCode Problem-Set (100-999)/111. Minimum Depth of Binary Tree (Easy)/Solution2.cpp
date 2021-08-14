// Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                auto node = q.front();
                q.pop();
                if (!node->left && !node->right) return ans;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++ans;
        }
        return -1;
    }
};
