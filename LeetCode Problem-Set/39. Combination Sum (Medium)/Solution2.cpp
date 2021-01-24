// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/ankuralld5999
// Time: O(NlogN)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &c, int t, int s, vector<int> &v){
        if(t==0){
            ans.push_back(v);
            return;
        }
        for(int i=s; i<c.size() && t>=0; i++){
            v.push_back(c[i]);
            dfs(c, t-c[i], i, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> v;
        dfs(c, t, 0, v);
        return ans;
    }
};
