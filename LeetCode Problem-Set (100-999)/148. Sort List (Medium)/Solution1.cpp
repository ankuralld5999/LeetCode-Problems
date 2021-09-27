// Problem: https://leetcode.com/problems/sort-list/
// Author: github.com/ankuralld5999
class Solution {
private:
    ListNode* merge(ListNode *a, ListNode *b) {
        if (!a || !b) return a ? a : b;
        ListNode *head;
        if (a->val < b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = head, *q = head, *prevP = NULL;
        while (q && q->next) {
            prevP = p;
            p = p->next;
            q = q->next->next;
        }
        prevP->next = NULL;
        return merge(sortList(head), sortList(p));
    }
};
