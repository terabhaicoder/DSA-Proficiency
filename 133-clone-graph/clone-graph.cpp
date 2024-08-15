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
    void dfs(Node* node, Node* clone_node, unordered_map<Node*,Node*>&mpp){

        for(auto n : node->neighbors){
            if(mpp.find(n)==mpp.end()){
                Node *clone = new Node(n->val);
                clone_node->neighbors.push_back(clone);
                mpp[n] = clone;
                dfs(n,clone,mpp); 
            }
            else{
                clone_node->neighbors.push_back(mpp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        Node* clone_node = new Node(node->val);
        unordered_map<Node*,Node*>mpp;
        mpp[node] = clone_node;

        dfs(node,clone_node,mpp);

        return clone_node;
    }
};