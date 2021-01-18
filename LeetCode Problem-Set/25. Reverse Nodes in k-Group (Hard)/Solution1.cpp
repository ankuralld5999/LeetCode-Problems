// Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *cur = dummy, *pre = dummy, *nex = dummy;
        int count = 0;
        
        while(cur->next != NULL){
            count++;
            cur = cur->next;
        }
        
        while(count >= k){
            cur = pre->next;
            nex = cur->next;
            for(int i=1; i<k; i++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;
        }
        return dummy->next;
    }
};
