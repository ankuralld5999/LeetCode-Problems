# [147. Insertion Sort List (Medium)](https://leetcode.com/problems/insertion-sort-list/)

<p>Sort a linked list using insertion sort.</p>

<ol>
</ol>

<p><img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif" style="height:180px; width:300px"><br>
<small>A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.<br>
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list</small><br>
&nbsp;</p>

<ol>
</ol>

<p><strong>Algorithm of Insertion Sort:</strong></p>

<ol>
	<li>Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.</li>
	<li>At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.</li>
	<li>It repeats until no input elements remain.</li>
</ol>

<p><br>
<strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 4-&gt;2-&gt;1-&gt;3
<strong>Output:</strong> 1-&gt;2-&gt;3-&gt;4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> -1-&gt;5-&gt;3-&gt;4-&gt;0
<strong>Output:</strong> -1-&gt;0-&gt;3-&gt;4-&gt;5
</pre>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Sort List (Medium)](https://leetcode.com/problems/sort-list/)
* [Insert into a Sorted Circular Linked List (Medium)](https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/insertion-sort-list/
// Author: github.com/ankuralld5999
// Time: O(N^2)
// Space: O(1)
lass Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *temp,*prev,*rear;
        prev=head;
        rear=head->next;
        
        while(rear != NULL){
            if((rear->val)<(prev->val)){
                prev->next=rear->next;
                temp=head;
                
                if(head->val > rear->val){
                    rear->next=head;
                    head=rear;
                    rear=prev->next;
                }
                
                else {
                    while(temp->next->val < rear->val)
                        temp=temp->next;
                    rear->next=temp->next;
                    temp->next=rear;
                }
                rear=prev->next;
            }
            
            else{
                prev=prev->next;
                rear=rear->next;
            }
        }
        
        return head;
    }
};
```

## Solution 2.

```cpp
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
```
