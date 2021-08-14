// Problem: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
lass Solution {
private:
    int ans = INT_MAX;
    void find(TreeNode *root, int cnt){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            ans = min(ans, cnt);
            return;
        }
        if(root->left)
            find(root->left, cnt+1);
        if(root->right)
            find(root->right, cnt+1);
    }
public:
    int minDepth(TreeNode* root) {
        find(root, 1);
        return ans==INT_MAX ? 0 : ans;
    }
};
