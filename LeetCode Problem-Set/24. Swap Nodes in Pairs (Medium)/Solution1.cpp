// Problem: https://leetcode.com/problems/swap-nodes-in-pairs/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *p=NULL, *q=NULL, *r=head;
        int n = 0;
        while(r!=NULL){
            n++;
            r=r->next;
        }
        r=head;
        for(int i=1; i<=n/2; i++){
            p = q;
            q = r;
            r = r->next;
            q->next = r->next;
            r->next = q;
            p==NULL ? head = r : p->next = r;
            r = q->next;
        }
        return head;
    }
};
