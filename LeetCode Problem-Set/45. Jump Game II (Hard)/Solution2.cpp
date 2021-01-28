// Problem: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0, des = 0, jumps = 0;
        
        for(int i=0;i<nums.size()-1;i++){
            des = max(des, i+nums[i]); 
                                         
            if(pos==i){
                pos = des;
                jumps++;
            }
        }
        return jumps;
    }
};

//Or

// Problem: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int jump(vector<int>& A) {
        int last = 0, next = 0, step = 0;
        for (int i = 0; i < A.size() && last < A.size() - 1; ++i) {
            if (i > last) {
                ++step;
                last = next;
            }
            next = max(next, i + A[i]);
        }
        return step;
    }
};
