// Problem Link - https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* eve = new ListNode(-1);
        ListNode* op1 = odd;
        ListNode* op2 = eve;
        ListNode* temp = head;
        ll flag = 1;
        while(temp!=nullptr)
        {
            if(flag&1)
                op1->next = temp, op1 = temp;
            else
                op2->next = temp, op2 = temp;
            temp = temp->next;
            flag = !flag;
        }
        op1->next = nullptr;
        op2->next = nullptr;
        op1->next = eve->next;
        return odd->next;
    }
};