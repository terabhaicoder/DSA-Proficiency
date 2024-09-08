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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int total = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            total++;
        }
        int t = total % k, sz = total / k;
        vector<ListNode*> result(k);
        temp = head;
        int currsz = 1, idx = 0;
        while(temp != NULL){
            result[idx] = temp;
            while(currsz < (t ? sz+1 : sz)){
                temp = temp->next;
                currsz++;
            } 
            if(t > 0) t--;
            idx++; currsz = 1;
            ListNode* forw = temp->next;
            temp->next = NULL;
            temp = forw;
        }
        return result;
    }
};