/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(!root) return NULL;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<Node*>tree;
            for(int i=0;i<n;i++){
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                tree.push_back(node);
            }
            for(int i=0;i<tree.size();i++){
                if(i==tree.size()-1) tree[i]->next = NULL;
                else tree[i]->next = tree[i+1]; 
            }
        }
        return root;
    }
};