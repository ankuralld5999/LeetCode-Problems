// Problem: https://leetcode.com/problems/word-break-ii
// Author: github.com/ankuralld5999
class Solution {
    unordered_map<string, vector<string>> dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s) != dp.end()) return dp[s];
        vector<string> result;
        for(string w : wordDict){
            if(s.substr(0, w.length()) == w){
                if(w.length() == s.length())
                    result.push_back(w);
                else{
                    vector<string> tmp = wordBreak(s.substr(w.length()), wordDict);
                    for(string t : tmp)
                        result.push_back(w + " " + t);
                }
            }
        }
        dp[s] = result;
        return result;
    }
};
