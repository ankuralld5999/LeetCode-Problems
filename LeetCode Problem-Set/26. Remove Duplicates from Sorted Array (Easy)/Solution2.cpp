// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int i = 0, j = 0, N = A.size();
        while (i < N) {
            A[j++] = A[i++];
            while (i < N && A[i] == A[i - 1]) ++i;
        }
        return j;
    }
};
