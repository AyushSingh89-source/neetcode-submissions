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
        if(node == nullptr){
            return nullptr;
        }

        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(int i=0; i< curr->neighbors.size(); i++){
                Node* neighbor = curr->neighbors[i];
                if(visited.find(neighbor) == visited.end()){
                    //this means ham is node pr nahi aaye hai abhi, unvisited hai ye node abhi
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};
