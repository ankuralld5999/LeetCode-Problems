// Problem: https://leetcode.com/problems/insertion-sort-list/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
lass Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *temp,*prev,*rear;
        prev=head;
        rear=head->next;
        
        while(rear != NULL){
            if((rear->val)<(prev->val)){
                prev->next=rear->next;
                temp=head;
                
                if(head->val > rear->val){
                    rear->next=head;
                    head=rear;
                    rear=prev->next;
                }
                
                else {
                    while(temp->next->val < rear->val)
                        temp=temp->next;
                    rear->next=temp->next;
                    temp->next=rear;
                }
                rear=prev->next;
            }
            
            else{
                prev=prev->next;
                rear=rear->next;
            }
        }
        
        return head;
    }
};
