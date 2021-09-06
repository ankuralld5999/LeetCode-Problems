// Problem: https://leetcode.com/problems/clone-graph/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        queue<Node*> q;
        unordered_map<Node*, Node*> m;
        m[node] = new Node(node->val);
        q.push(node);
        while (q.size()) {
            auto p = q.front();
            q.pop();
            auto copy = m[p];
            for (auto nei : p->neighbors) {
                if (!m.count(nei)) {
                    m[nei] = new Node(nei->val);
                    q.push(nei);
                }
                copy->neighbors.push_back(m[nei]);
            }
        }
        return m[node];
    }
};
