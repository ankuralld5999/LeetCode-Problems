// Problem: https://leetcode.com/problems/clone-graph/
// Author: github.com/ankuralld5999
// Time: O(N)
// Space: O(N)
class Solution {
    unordered_map<Node*, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (m.count(node) == 0) {
            auto copy = new Node(node->val);
            m[node] = copy;
            for (auto nei : node->neighbors) copy->neighbors.push_back(cloneGraph(nei));
        }
        return m[node];
    }
};
