# [117. Populating Next Right Pointers in Each Node II (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

<p>Given a binary tree</p>

<pre>struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
</pre>

<p>Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.</p>

<p>Initially, all next pointers are set to <code>NULL</code>.</p>

<p>&nbsp;</p>

<p><strong>Follow up:</strong></p>

<ul>
	<li>You may only use constant extra space.</li>
	<li>Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/15/117_sample.png" style="width: 640px; height: 218px;"></p>

<pre><strong>Input:</strong> root = [1,2,3,4,5,null,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,7,#]
<strong>Explanation: </strong>Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the given tree is less than <code>6000</code>.</li>
	<li><code>-100&nbsp;&lt;= node.val &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Populating Next Right Pointers in Each Node (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

## Solution 1. 

```cpp
// Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node *dummy = new Node(0);
            int size = q.size();
            while(size-- > 0){
                Node *node = q.front();
                q.pop();
                dummy->next = node;
                dummy = dummy->next;
                
                if(node->left != NULL)
                    q.push(node->left);
                
                if(node->right != NULL)
                    q.push(node->right);
            }
        }
        return root;
    }
};
```

## Solution 2. DFS

```cpp
// Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(H)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        Node head, *tail = &head;
        for (auto node = root; node; node = node->next) {
            if (node->left) {
                tail->next = node->left;
                tail = tail->next;
            }
            if (node->right) {
                tail->next = node->right;
                tail = tail->next;
            }
        }
        connect(head.next);
        return root;
    }
};
```

## Solution 3. 

```cpp
// Problem: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        auto first = root;
        while (first) {
            Node head, *tail = &head;
            for (auto node = first; node; node = node->next) {
                if (node->left) {
                    tail->next = node->left;
                    tail = tail->next;
                }
                if (node->right) {
                    tail->next = node->right;
                    tail = tail->next;
                }
            }
            first = head.next;
        }
        return root;
    }
};
```