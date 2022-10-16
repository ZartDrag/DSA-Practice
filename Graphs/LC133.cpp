class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)    return NULL;
        unordered_map<Node*,Node*> clone;
        queue<Node*> q;
        q.push(node);
        clone[node] = new Node(node->val);
        while(!q.empty()) {
            Node* ptr = q.front();
            q.pop();
            for(Node* adj:ptr->neighbors) {
                if(clone.find(adj) == clone.end()){
                    clone[adj] = new Node(adj->val);
                    q.push(adj);
                }
                clone[ptr]->neighbors.push_back(clone[adj]);
            }
        }    
        return clone[node];
    }
};