/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>>st;
        vector<int>inorder,preorder,postorder;
        if(root==NULL) return postorder;
        st.push({root,1});
        while(!st.empty()){
            auto it = st.top();
            st.pop();

            if(it.second==1){
                preorder.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left!=NULL) st.push({it.first->left,1});
            }

            else if(it.second==2){
                inorder.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->right!=NULL) st.push({it.first->right,1});
            }
            else{
                postorder.push_back(it.first->val);
            }
        }
        return postorder;
    }
};