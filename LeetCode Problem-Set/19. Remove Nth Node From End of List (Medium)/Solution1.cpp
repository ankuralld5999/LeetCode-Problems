class Solution {
private:
    int findLength(ListNode *head){
        if(head == NULL)
            return 0;
        int l =0;
        while(head != NULL){
            head = head->next;
            l++;
        }
        return l;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int n = findLength(head);
        if(k > n)
            return head;
        if(n==k)
            return head->next;
        k = n-k;
        n=0;
        ListNode *prev=NULL, *curr=head;
        while(n!=k){
            prev = curr;
            curr = curr->next;
            n++;
        }
        prev->next = curr->next;
        return head;
    }
};
