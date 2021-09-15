// Problem: https://leetcode.com/problems/linked-list-cycle/
// Author: github.com/ankuralld5999
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode *start = head, *end = head;
        while(end!=NULL && end->next!=NULL){
            start = start->next;
            end = end->next->next;
            if(start == end)
                return true;
        }
        return false;
    }
};
