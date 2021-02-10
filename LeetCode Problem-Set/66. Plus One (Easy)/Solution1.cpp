// Problem: https://leetcode.com/problems/plus-one/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i=digits.size()-1;
        while(carry && i>=0){
            if(digits[i]==9){
                digits[i] = 0;
                carry = 1;
            }
            else{
                digits[i]++;
                carry = 0;
            }
            i--;
        }
        if(carry == 1){
            vector<int> v = {1};
            for(int x : digits)
                v.push_back(x);
            return v;
        }
        return digits;
    }
};
