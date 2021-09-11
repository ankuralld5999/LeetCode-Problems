// Problem: https://leetcode.com/problems/copy-list-with-random-pointer/
// Author: github.com/ankuralld5999
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
  		if(!head) return NULL;
  		RandomListNode *new_head, *p, *q, *prev;
  		map<RandomListNode*, RandomListNode*> m;
  		m[NULL] = NULL;
  		new_head = new RandomListNode(head->label);
  		m[head] = new_head;
  		p = head->next;
  		prev = new_head;
  		while(p){
  			q = new RandomListNode(p->label);
  			m[p] = q;
  			prev->next = q;
  			prev = q;
  			p = p->next;
  		}
  		p = head;
  		q = new_head;
  		while(p){
  			q->random = m[p->random];
  			p = p->next;
  			q = q->next;
  		}
  		return new_head;
    }
};
