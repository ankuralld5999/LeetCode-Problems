// Problem: https://leetcode.com/problems/count-and-say/
// Author: https://github.com/ankuralld5999
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string main = "11";
        for(int num=3; num<=n; num++){
            string s = "";
            int count = 0;
            char c;
            for(int i=0; i<main.size(); i++){
                if(i==0){
                    c=main[0];
                    count++;
                }
                else if(main[i]==c)
                    count++;
                else{
                    s += to_string(count) + c;
                    c = main[i];
                    count=1;
                }
            }
            s += to_string(count) + c;
            main = s;
        }
        return main;
    }
};
