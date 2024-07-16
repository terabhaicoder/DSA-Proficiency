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
    TreeNode* find(TreeNode* root,int p,int q){
        if(root==NULL || root->val==p || root->val==q) return root;
        TreeNode* left = find(root->left,p,q);
        TreeNode* right = find(root->right,p,q);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
    bool findPath(TreeNode* LCA,int target,string &path){
        if(!LCA) return false;

        if(LCA->val==target)return true;
        path.push_back('L');
        if(findPath(LCA->left,target,path)) return true;
        path.pop_back();

        path.push_back('R');
        if(findPath(LCA->right,target,path)) return true;
        path.pop_back();

        return false;
        

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = find(root,startValue,destValue);

        string lts = "";
        string ltd = "";
        findPath(LCA,startValue,lts);
        findPath(LCA,destValue,ltd);
        string result = "";
        for(int i=0;i<lts.size();i++){
            result+="U";
        }
        result+=ltd;
        return result;

    }
};