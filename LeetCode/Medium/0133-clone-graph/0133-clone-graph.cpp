/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        // keep tracking of original -> clone
        unordered_map<Node*, Node*> copies;
        queue<Node*> q;
        // first element - basically create a clone of first node with value
        // node->val
        copies[node] = new Node(node->val);
        q.push(node);
        while (!q.empty()) {
            // standard bfs
            Node* curr = q.front();
            q.pop();

            for (Node* neighbour : curr->neighbors) {
                // if our hashmap doesn't have neighbours, then add it to
                // hashmap and make the clone and push original to queue
                if (!copies.contains(neighbour)) {
                    copies[neighbour] = new Node(neighbour->val);
                    q.push(neighbour);
                }
                //**** current node's clone -> neighbours -> add neighbours clone
                copies[curr]->neighbors.push_back(copies[neighbour]);
            }
        }
        return copies[node];
    }
};