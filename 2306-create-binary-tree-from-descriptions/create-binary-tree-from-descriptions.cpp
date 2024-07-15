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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        map<int,TreeNode*>mpp;
        unordered_set<int>st;
        for(auto &it : descriptions){
            if(mpp.find(it[0])==mpp.end()){
                TreeNode* newnode = new TreeNode(it[0]);
                mpp[it[0]] = newnode;
            }
            if(mpp.find(it[1])==mpp.end()){
                TreeNode* newnode = new TreeNode(it[1]);
                mpp[it[1]] = newnode;
            }
            if(it[2]==1) mpp[it[0]]->left = mpp[it[1]];
            else  mpp[it[0]]->right = mpp[it[1]];

            st.insert(it[1]);
        } 
        for(auto &it : descriptions){
            if(st.find(it[0])==st.end()) return mpp[it[0]];
            else continue;
        }
        return new TreeNode(-1);
    }
};