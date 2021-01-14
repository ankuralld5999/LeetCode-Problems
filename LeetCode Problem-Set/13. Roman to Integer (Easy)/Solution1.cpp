// Problem: https://leetcode.com/problems/two-sum/
// Author: github.com/ankuralld5999
class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0 ; i < n ; i++){
            switch(s[i]){
                case 'I':
                    if(s[i+1] == 'V' && i+1 < n){
                        sum+=4;
                        i++;}
                    else if (s[i+1] == 'X' && i+1 < n){
                        sum+=9;
                        i++;}
                    else
                        sum+=1;
                    break;
                case 'V':
                    sum+=5;
                    break;
                case 'X':
                    if(s[i+1] == 'L' && i+1 < n){
                        sum+=40;
                        i++;}
                    else if (s[i+1] == 'C' && i+1 < n){
                        sum+=90;
                        i++;}
                    else
                        sum+=10;
                    break;
                case 'L':
                    sum+=50;
                    break;
                case 'C':
                    if(s[i+1] == 'D' && i+1 < n){
                        sum+=400;
                        i++;}
                    else if (s[i+1] == 'M' && i+1 < n){
                        sum+=900;
                        i++;}
                    else
                        sum+=100;
                    break;
                case 'D':
                    sum+=500;
                    break;
                case 'M':
                    sum+=1000;
                    break;
                default:
                    break;
            }
        }
        return sum;
    }
};
