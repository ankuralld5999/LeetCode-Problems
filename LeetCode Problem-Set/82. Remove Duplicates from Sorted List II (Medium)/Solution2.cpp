// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode h, *tail = &h;
        while (head) {
            if (head->next == NULL || head->next->val != head->val) {
                tail->next = head;
                tail = head;
                head = head->next;
            } else {
                int val = head->val;
                while (head && head->val == val) head = head->next;
            }
        }
        tail->next = NULL;
        return h.next;
    }
};
