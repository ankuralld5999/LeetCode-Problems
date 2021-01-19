// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int j = 0;
        for (int n : A) {
            if (j - 1 < 0 || A[j - 1] != n) A[j++] = n;
        }
        return j;
    }
};
