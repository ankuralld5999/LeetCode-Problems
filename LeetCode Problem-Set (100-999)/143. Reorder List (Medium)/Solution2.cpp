// Problem: https://leetcode.com/problems/reorder-list/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
private:
    ListNode *reverseList(ListNode *head) {
        ListNode newHead;
        while (head) {
            auto p = head;
            head = head->next;
            p->next = newHead.next;
            newHead.next = p;
        }
        return newHead.next;
    }
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *fast = head, *slow = head, *rightHead;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        rightHead = slow->next;
        slow->next = NULL;
        rightHead = reverseList(rightHead);
        while (rightHead) {
            auto p = rightHead;
            rightHead = rightHead->next;
            p->next = head->next;
            head->next = p;
            head = p->next;
        }
    }
};
