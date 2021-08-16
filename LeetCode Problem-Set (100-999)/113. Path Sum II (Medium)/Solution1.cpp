// Problem: https://leetcode.com/problems/path-sum-ii/
// Author: github.com/ankuralld5999
class Solution {
private:
    void solver(vector<vector<int>> &v,vector<int> temp, TreeNode* root, int targetSum, int currentSum){
        if(root==NULL)
            return;
        currentSum += root->val;
        temp.push_back(root->val);
        if(currentSum==targetSum){
            if(!root->left && !root->right)
                v.push_back(temp);
        }
        
        solver(v, temp, root->left, targetSum, currentSum);
        solver(v, temp, root->right, targetSum, currentSum);
        return;
            
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> temp;
        solver(v, temp, root, targetSum, 0);
        
        return v;
    }
};
