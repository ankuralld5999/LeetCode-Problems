// Problem: https://leetcode.com/problems/linked-list-cycle-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        auto p = head, q = head;
        while (p && p->next) {
            p = p->next->next;
            q = q->next;
            if (p == q) break;
        }
        if (!p || !p->next) return NULL;
        p = head;
        for (; p != q; p = p->next, q = q->next);
        return p;
    }
};
