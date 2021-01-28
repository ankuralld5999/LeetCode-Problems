// Problem: https://leetcode.com/problems/multiply-strings/
// Author: https://github.com/ankuralld5999
class Solution {
public:
    string multiply(string num1, string num2) {
        int M=num1.size(), N=num2.size();
        string ans(M+N,'0');
        for(int i=0; i<M; i++){
            int j=0, carry = 0;
            while(j<N || carry){
                if(j<N)
                    carry += (num1[M-1-i]-'0')*(num2[N-1-j]-'0');
                carry += ans[i+j]-'0';
                ans[i+j] = carry%10 + '0';
                carry /= 10;
                j++;
            }
        }
        while(ans.size()>1 && ans.back()=='0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
