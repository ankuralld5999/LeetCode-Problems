// Problem: https://leetcode.com/problems/combination-sum-ii/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &c, int t, int s, vector<int> &v){
        if(t==0){
            ans.push_back(v);
            return;
        }
        for(int i=s; i<c.size() && t>=c[i]; i++){
            if(i!=s && c[i]==c[i-1])
                continue;
            v.push_back(c[i]);
            dfs(c, t-c[i], i+1, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
         vector<int> v;
        sort(c.begin(), c.end());
        dfs(c, t, 0, v);
        return ans;
    }
};
