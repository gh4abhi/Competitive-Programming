// Problem Link - https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

#define ll int

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* pre = head;
        ListNode* temp = head->next;
        while(temp)
        {
            ListNode* node = new ListNode(__gcd(pre->val,temp->val));
            pre->next = node;
            node->next = temp;
            pre = temp;
            temp = temp->next;
        }
        return head;
    }
};
