// Problem: https://leetcode.com/problems/linked-list-cycle-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return head;
        ListNode *start = head, *end = head;
        
        while(end!=NULL && end->next!=NULL){
            start = start->next;
            end = end->next->next;
            if(start == end){
                start = head;
                while(start != end){
                    start = start->next;
                    end = end->next;
                }
                return start;
            }
        }
        return NULL;
    }
};
