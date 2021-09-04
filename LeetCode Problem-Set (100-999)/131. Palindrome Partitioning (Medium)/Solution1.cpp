// Problem: https://leetcode.com/problems/palindrome-partitioning
// Author: github.com/ankuralld5999
class Solution {
private:
    bool isPalindrome(string str){
        int l=0;
        int r=str.length()-1;
        if(l==r)
            return true;
        while(l<r){
            if(str[l] != str[r])
                return false;
            l++;r--;
        }
        return true;
    }

void findAll(string s, vector<vector<string>> &ans, vector<string>& temp){
    if(s.length()==0)
        ans.push_back(temp);
    for(int i=0; i<s.length(); i++){  
           string leftPar= s.substr(0,i+1);
           if(isPalindrome(leftPar)){
               temp.push_back(leftPar);
               findAll(s.substr(i+1), ans, temp); 
               temp.pop_back();
           }
       }
}
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        findAll(s, ans, temp);
        return ans;
    }
};
