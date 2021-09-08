// Problem: https://leetcode.com/problems/candy/
// Author: github.com/ankuralld5999
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(),count=0;
        vector<int> left(n,1), right(n,1);
        for(int i=1; i<n; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                left[i] = left[i-1] + 1;
            }
        }
        for(int i=n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                right[i] = right[i+1] + 1;
            }
        }
        for(int i=0; i<n; i++)
        {
            count += max(left[i], right[i]);
        }
        return count;
    }
};
