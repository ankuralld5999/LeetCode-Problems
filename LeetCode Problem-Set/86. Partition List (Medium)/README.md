# [86. Partition List (Medium)](https://leetcode.com/problems/partition-list/)

<p>Given a linked list and a value <em>x</em>, partition it such that all nodes less than <em>x</em> come before nodes greater than or equal to <em>x</em>.</p>

<p>You should preserve the original relative order of the nodes in each of the two partitions.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> head = 1-&gt;4-&gt;3-&gt;2-&gt;5-&gt;2, <em>x</em> = 3
<strong>Output:</strong> 1-&gt;2-&gt;2-&gt;4-&gt;3-&gt;5
</pre>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/partition-list/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        queue<int> q1, q2;
        int n = 0;
        ListNode *t = head;
        while(t){
            if(t->val < x)
                q1.push(t->val);
            else
                q2.push(t->val);
            t = t->next;
        }
        n = n - q1.size() - q2.size();
        t = head;
        while(t){
            if(!q1.empty()){
                t->val = q1.front();
                q1.pop();
            }
            else if(!q2.empty()){
                t->val = q2.front();
                q2.pop();
            }
            t = t->next;
        }
        return head;
    }
};
```

## Solution 2.

```cpp
// Problem: https://leetcode.com/problems/partition-list/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode ltHead, geHead, *ltTail = &ltHead, *geTail = &geHead;
        while (head) {
            auto p = head;
            head = head->next;
            if (p->val < x) {
                ltTail->next = p;
                ltTail = p;
            } else {
                geTail->next = p;
                geTail = p;
            }
        }
        ltTail->next = geHead.next;
        geTail->next = NULL;
        return ltHead.next;
    }
};
```
