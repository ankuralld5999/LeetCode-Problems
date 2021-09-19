// Problem: https://leetcode.com/problems/reorder-list/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
private:
    ListNode *reverse(ListNode* head) {
        ListNode dummy;
        while (head) {
            auto node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
    int getLength(ListNode *head) {
        int len = 0;
        for (; head; head = head->next) ++len;
        return len;
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        int len = (getLength(head) - 1) / 2;
        ListNode *p = head, *q;
        while (len--) p = p->next;
        q = p->next;
        p->next = NULL;
        q = reverse(q);
        p = head;
        while (q) {
            auto node = q;
            q = q->next;
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
    }
};
