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
    int gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        if (b == 0)
        {
            return a;
        }

        return a >= b ? gcd( a % b , b) : gcd(a, b % a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* it = head;
        while (it->next)
        {
            ListNode* next = it->next;
            ListNode* node = new ListNode(gcd(it->val, next->val), next);
            it->next = node;
            it = next;
        }
        return head;

    }
};