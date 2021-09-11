// Problem: https://leetcode.com/problems/copy-list-with-random-pointer/
// Author: github.com/ankuralld5999
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) 
            return head;
        
        auto cur = head;
        Node* dummy_head = nullptr;
        // inter
        while(cur){
            auto cp_node = new Node(cur->val);
            if(!dummy_head) 
                dummy_head = cp_node;
            
            cp_node->next = cur->next;
            cp_node->random = cur->random;
            cur->next = cp_node;
            cur = cp_node->next;
        }
        // switch to cp
        cur = head;
        while(cur){
            if(cur->random) 
                cur->next->random = cur->random->next;
            
            cur = cur->next->next;
        }
        cur = head;
        Node* cp_cur = nullptr;
        while(cur){
            if(!cp_cur){
               cp_cur = cur->next; 
            }else{
               cp_cur->next = cur->next; 
               cp_cur = cp_cur->next;  
            }
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy_head;
    }
};
