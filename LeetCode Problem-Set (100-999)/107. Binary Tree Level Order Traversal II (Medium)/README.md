# [107. Binary Tree Level Order Traversal II (Easy)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

<p>Given a binary tree, return the <i>bottom-up level order</i> traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).</p>

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
return its bottom-up level order traversal as:<br>
</p><pre>[
  [15,7],
  [9,20],
  [3]
]
</pre>
<p></p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [Average of Levels in Binary Tree (Easy)](https://leetcode.com/problems/average-of-levels-in-binary-tree/)

## Solution 1.

```cpp
// Problem: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```
