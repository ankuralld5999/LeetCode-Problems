// Problem: https://leetcode.com/problems/merge-k-sorted-lists/
// Author: github.com/ankuralld5999
// Time: O(NlogK)
// Space: O(1)
class Solution {
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        for(int i=lists.size()-1; i>0; i--){
            lists[i-1] = mergeTwoLists(lists[i-1], lists[i]);
            lists.pop_back();
        }
        return lists[0];
    }
};
