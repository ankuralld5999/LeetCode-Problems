// Problem: https://leetcode.com/problems/palindrome-partitioning-ii/
// Author: github.com/ankuralld5999
class Solution {
public:
  int minCut(string s) {
    int n = s.size();
    vector<int> f(n+1);
    iota(f.begin(), f.end(), -1);
    for(int i=0; i<n; i++){
      for (int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)
        f[i+j+1] = min(f[i+j+1], f[i-j]+1);
      for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++)
        f[i+j+1] = min(f[i+j+1], f[i-j+1]+1);
    }
    return f[n];
  }
};
