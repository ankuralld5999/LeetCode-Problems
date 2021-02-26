// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
      if(head==NULL)
        return head;
      ListNode* t = head;
      while(t->next){
          if(t->val == t->next->val)
              t->next = t->next->next;
          else
              t = t->next;
      }
      return head;
  }
};
