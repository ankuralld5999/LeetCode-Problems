# [142. Linked List Cycle II (Medium)](https://leetcode.com/problems/linked-list-cycle-ii/)

<p>Given a linked list, return the node where the cycle begins. If there is no cycle, return <code>null</code>.</p>

<p>There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the&nbsp;<code>next</code>&nbsp;pointer. Internally, <code>pos</code>&nbsp;is used to denote the index of the node that&nbsp;tail's&nbsp;<code>next</code>&nbsp;pointer is connected to.&nbsp;<strong>Note that&nbsp;<code>pos</code>&nbsp;is not passed as a parameter</strong>.</p>

<p><strong>Notice</strong> that you <strong>should not modify</strong> the linked list.</p>

<p><strong>Follow up:</strong></p>

<p>Can you solve it using <code>O(1)</code> (i.e. constant) memory?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" style="height: 145px; width: 450px;">
<pre><strong>Input:</strong> head = [3,2,0,-4], pos = 1
<strong>Output:</strong> tail connects to node index 1
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the second node.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 105px; width: 201px;">
<pre><strong>Input:</strong> head = [1,2], pos = 0
<strong>Output:</strong> tail connects to node index 0
<strong>Explanation:</strong> There is a cycle in the linked list, where tail connects to the first node.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 65px; width: 65px;">
<pre><strong>Input:</strong> head = [1], pos = -1
<strong>Output:</strong> no cycle
<strong>Explanation:</strong> There is no cycle in the linked list.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the list is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> is <code>-1</code> or a <strong>valid index</strong> in the linked-list.</li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Linked List Cycle (Easy)](https://leetcode.com/problems/linked-list-cycle/)
* [Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/linked-list-cycle-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return head;
        ListNode *start = head, *end = head;
        
        while(end!=NULL && end->next!=NULL){
            start = start->next;
            end = end->next->next;
            if(start == end){
                start = head;
                while(start != end){
                    start = start->next;
                    end = end->next;
                }
                return start;
            }
        }
        return NULL;
    }
};
```

## Solution 2.

```cpp
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
```
