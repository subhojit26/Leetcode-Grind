/*
 * Problem  : 133. Clone Graph
 * Difficulty: Medium
 * Topics   : Hash Table, Depth-First Search, Breadth-First Search, Graph Theory
 * URL      : https://leetcode.com/problems/clone-graph/
 */

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
        if(node==NULL){
            return node;
        }

        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        visited[node]=new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();

            for(auto nei:curr->neighbors){
                if(!visited[nei]){
                    visited[nei]=new Node(nei->val);
                    q.push(nei);
                }
                visited[curr]->neighbors.push_back(visited[nei]);
            }
        }
        return visited[node];
    }
};