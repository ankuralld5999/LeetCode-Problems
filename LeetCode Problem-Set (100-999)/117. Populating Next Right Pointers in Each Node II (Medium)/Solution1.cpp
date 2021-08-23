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
