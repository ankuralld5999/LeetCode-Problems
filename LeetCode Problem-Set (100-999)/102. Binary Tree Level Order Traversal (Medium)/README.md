# [102. Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)

<p>Given a binary tree, return the <i>level order</i> traversal of its nodes' values. (ie, from left to right, level by level).</p>

<p>
For example:<br>
Given binary tree <code>[3,9,20,null,null,15,7]</code>,<br>
</p><pre>    3
   / \
  9  20
    /  \
   15   7
</pre>
<p></p>
<p>
return its level order traversal as:<br>
</p><pre>[
  [3],
  [9,20],
  [15,7]
]
</pre>
<p></p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Binary Tree Zigzag Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
* [Binary Tree Level Order Traversal II (Easy)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
* [Minimum Depth of Binary Tree (Easy)](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
* [Binary Tree Vertical Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-vertical-order-traversal/)
* [Average of Levels in Binary Tree (Easy)](https://leetcode.com/problems/average-of-levels-in-binary-tree/)
* [N-ary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)
* [Cousins in Binary Tree (Easy)](https://leetcode.com/problems/cousins-in-binary-tree/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int cnt = q.size();
            ans.emplace_back();
            while (cnt--) {
                root = q.front();
                q.pop();
                ans.back().push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        q.push(root);
        while(q.size()){
            int size = q.size();
            vector<int> v;
            for(int i=0; i<size; i++){
                TreeNode *t = q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
```
