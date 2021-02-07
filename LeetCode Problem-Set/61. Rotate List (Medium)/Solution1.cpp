// Problem: https://leetcode.com/problems/rotate-list/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int countNode(ListNode *head){
        if(!head)
            return 0;
        int n = 0;
        while(head){
            head = head->next;
            n++;
        }
        return n;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = countNode(head);
        if(n==0)
            return head;
        k = k%n;
        if(!head || !head->next || k==0)
            return head;
        ListNode *temp = head, *prev;
        while(temp!=NULL){
            if(k == n)
                break;
            k++;
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        prev = temp;
        while(temp->next)
            temp = temp->next;
        temp->next = head;
        return prev;
    }
};
