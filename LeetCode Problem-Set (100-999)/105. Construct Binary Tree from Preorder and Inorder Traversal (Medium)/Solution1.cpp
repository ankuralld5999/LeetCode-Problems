
// Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    map<int, int> m;
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if(pre.size() != in.size())
            return NULL;
        int n = in.size();
        for(int i=0; i<n; i++)
            m.insert(pair<int, int>(in[i], i));
    
        return helper(pre, 0, n-1);
    }
    
    int p=0;
    
    TreeNode *helper(vector<int>& pre, int start, int end){
    if(start > end)
        return NULL;
    
    TreeNode* root = new TreeNode(pre[p++]);
    
    if(start==end)
        return root;
        
    int index = m[root->val];
    
    root->left = helper(pre, start, index-1);
    root->right = helper(pre, index+1, end);
    return root;
    }
};
