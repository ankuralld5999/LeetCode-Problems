// Problem: https://leetcode.com/problems/add-two-numbers/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        int carry = 0;
        ListNode dummy, *tail = &dummy;
        while (a || b || carry) {
            if (a) {
                carry += a->val;
                a = a->next;
            }
            if (b) {
                carry += b->val;
                b = b->next;
            }
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;
        }
        return dummy.next;
    }
};
