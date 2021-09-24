// Problem: https://leetcode.com/problems/insertion-sort-list/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy, *p;
        while (head) {
            auto *n = head;
            head = head->next;
            p = &dummy;
            while (p->next && p->next->val < n->val) p = p->next;
            n->next = p->next;
            p->next = n;
        }
        return dummy.next;
    }
};
