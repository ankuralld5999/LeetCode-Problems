// Problem: https://leetcode.com/problems/partition-list/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        queue<int> q1, q2;
        int n = 0;
        ListNode *t = head;
        while(t){
            if(t->val < x)
                q1.push(t->val);
            else
                q2.push(t->val);
            t = t->next;
        }
        n = n - q1.size() - q2.size();
        t = head;
        while(t){
            if(!q1.empty()){
                t->val = q1.front();
                q1.pop();
            }
            else if(!q2.empty()){
                t->val = q2.front();
                q2.pop();
            }
            t = t->next;
        }
        return head;
    }
};
