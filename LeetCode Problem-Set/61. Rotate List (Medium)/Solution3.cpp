// Problem: https://leetcode.com/problems/rotate-list/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
    int getLength(ListNode *head) {
        int len = 0;
        for (; head; head = head->next, ++len);
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        int len = getLength(head);
        k %= len;
        if (k == 0) return head;
        auto p = head, q = head;
        while (k--) q = q->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        auto h = p->next;
        q->next = head;
        p->next = NULL;
        return h;
    }
};
