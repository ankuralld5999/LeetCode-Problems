// Problem: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> s;
        s.emplace(root, 0);
        int ans = 0;
        while (s.size()) {
            auto p = s.top();
            root = p.first;
            int sum = p.second * 10 + root->val;
            s.pop();
            if (!root->left && !root->right) ans += sum;
            if (root->right) s.emplace(root->right, sum);
            if (root->left) s.emplace(root->left, sum);
        }
        return ans;
    }
};
