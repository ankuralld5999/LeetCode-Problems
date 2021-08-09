// Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        q.push(root);
        bool flag = false;
        while(q.size()){
            int size = q.size();
            vector<int> v;
            for(int i=0; i<size; i++){
                TreeNode *t = q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(flag)
                reverse(v.begin(), v.end());
            ans.push_back(v);
            flag = !flag;
        }
        return ans;
    }
};
