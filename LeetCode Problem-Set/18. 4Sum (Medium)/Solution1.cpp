// Problem: https://leetcode.com/problems/4sum/
// Author: github.com/ankuralld5999
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
    if(arr.size() == 0)
        return res;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<n ;i++){
        for(int j=i+1; j<n; j++){
            int target_2 = target - arr[i] - arr[j];
            int front = j+1;
            int back = n-1;
            while(front < back){
                
                if(arr[front] + arr[back] < target_2)
                    front++;
                else if(arr[front] + arr[back] > target_2)
                    back--;
                else{
                    vector<int> quard;
                    quard.push_back(arr[i]);
                    quard.push_back(arr[j]);
                    quard.push_back(arr[front]);
                    quard.push_back(arr[back]);
                    res.push_back(quard);
                    
                    while(front < back && arr[front] == quard[2]) ++front;
                    while(front < back && arr[back] == quard[3]) --back;
                }
            }
            while(j+1 < n && arr[j+1] == arr[j]) ++j;
        }
        while(i+1 < n && arr[i+1] == arr[i]) ++i;
    }
    return res;
    }
};
