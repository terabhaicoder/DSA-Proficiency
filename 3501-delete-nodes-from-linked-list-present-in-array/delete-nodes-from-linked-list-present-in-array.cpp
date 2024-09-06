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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i=0;i<n;i++)st.insert(nums[i]);
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = head;
        // while(st.find(temp->val)!=st.end()){
        //     temp = temp->next;
        // }
        ListNode* dtemp = dummy;
        //dummy->next = temp;
        while(temp!=NULL){
            if(st.find(temp->val)==st.end()){
                dtemp->next = temp;
                dtemp = temp;
            }
            else{
                dtemp->next = NULL;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};