// Problem: https://leetcode.com/problems/insert-interval/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& A, vector<int>& B) {
        vector<vector<int>> ans;
        int s=B[0], e=B[1];
        for(vector<int> C: A){
            if(s>e)
                ans.push_back(C);
            else if(C[0] > e){
                ans.push_back({s, e});
                ans.push_back(C);
                s = e+1;
            }
            else if(C[1] < s)
                ans.push_back(C);
            else{
                s = min(s, C[0]);
                e = max(e, C[1]);
            }
        }
        if(s <= e)
            ans.push_back({s, e});
        return ans;
    }
};
