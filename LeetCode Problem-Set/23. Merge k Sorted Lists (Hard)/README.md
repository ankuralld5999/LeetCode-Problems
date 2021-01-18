# [23. Merge k Sorted Lists (Hard)](https://leetcode.com/problems/merge-k-sorted-lists/)

<p>Merge <em>k</em> sorted linked lists and return it as one sorted list. Analyze and describe its complexity.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>
[
&nbsp; 1-&gt;4-&gt;5,
&nbsp; 1-&gt;3-&gt;4,
&nbsp; 2-&gt;6
]
<strong>Output:</strong> 1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Oracle](https://leetcode.com/company/oracle), [Adobe](https://leetcode.com/company/adobe), [IXL](https://leetcode.com/company/ixl), [LinkedIn](https://leetcode.com/company/linkedin), [Wish](https://leetcode.com/company/wish), [Apple](https://leetcode.com/company/apple), [Uber](https://leetcode.com/company/uber), [VMware](https://leetcode.com/company/vmware), [Yahoo](https://leetcode.com/company/yahoo), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Salesforce](https://leetcode.com/company/salesforce), [Samsung](https://leetcode.com/company/samsung), [Mathworks](https://leetcode.com/company/mathworks)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Heap](https://leetcode.com/tag/heap/)

**Similar Questions**:
* [Merge Two Sorted Lists (Easy)](https://leetcode.com/problems/merge-two-sorted-lists/)
* [Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii/)

## Solution 1. Heap

```cpp
// Problem: https://leetcode.com/problems/merge-k-sorted-lists/
// Author: github.com/ankuralld5999
// Time: O(NlogK)
// Space: O(K)
struct Cmp {
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0), *tail = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, Cmp> q;
        for (auto list : lists) {
            if (list) q.push(list); // avoid pushing NULL list.
        }
        while (q.size()) {
            auto node = q.top();
            q.pop();
            if (node->next) q.push(node->next);
            tail->next = node;
            tail = node;
        }
        return dummy.next;
    }
};
```

## Solution 2. Divide And Conquer (Merge Sort)

```cpp
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
```
