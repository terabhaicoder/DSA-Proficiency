/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        if(!head) return ans;
        int id = 0;
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        while(top<=bottom && left<=right ){
            if(id==0){
                for(int i=left;head!=NULL && i<=right;i++){
                    ans[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }
            if(id==1){
                for(int i=top; head!=NULL && i<=bottom;i++){
                    ans[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }
            if(id==2){
                for(int i=right;head!=NULL && i>=left;i--){
                    ans[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }
            if(id==3){
                for(int i=bottom; head!=NULL && i>=top;i--){
                    ans[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            id++;
            if(id==4) id = 0;
        }
        return ans;
    }
};