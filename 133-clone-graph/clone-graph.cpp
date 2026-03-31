class Solution {
public:
    unordered_map<Node*, Node*> mapping;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If clone exists, return it
        if (mapping.find(node) != mapping.end()) {
            return mapping[node];
        }

        // Create new node and register in map
        Node* clone = new Node(node->val);
        mapping[node] = clone;

        // Traverse neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};