// Problem: https://leetcode.com/problems/merge-two-sorted-lists/
// Author: github.com/ankuralld5999
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2!=0)
            return false;
        stack<char> st;
        for(auto x : s){
            if(x==')'){
                if(st.empty() || st.top()!='(')
                    return false;
                st.pop();
            }
            else if(x=='}'){
                if(st.empty() || st.top()!='{')
                    return false;
                st.pop();
            }
            else if(x==']'){
                if(st.empty() || st.top()!='[')
                    return false;
                st.pop();
            }
            else
                st.push(x);
        }
        if(st.empty())
            return true;
        return false;
    }
};
