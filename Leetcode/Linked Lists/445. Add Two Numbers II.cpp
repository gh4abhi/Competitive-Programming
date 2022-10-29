// Problem Link - https://leetcode.com/problems/add-two-numbers-ii/

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
    
    void reverse(ListNode* &l1)
    {
        ListNode* pre = nullptr;
        while(l1)
        {
            ListNode* nex = l1->next;
            l1->next = pre;
            pre = l1;
            l1 = nex;
        }
        l1 = pre;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverse(l1);
        reverse(l2);
        ListNode* dummy = new ListNode(-1);
        ListNode* ok = dummy;
        ll carry = 0;
        while(l1 or l2 or carry)
        {
            ll op = 0;
            if(l1)
                op += l1->val, l1 = l1->next;
            if(l2)
                op += l2->val, l2 = l2->next;
            op += carry;
            carry = op/10;
            ListNode *cur = new ListNode(op%10);
            ok->next = cur;
            ok = cur;
        }
        dummy = dummy->next;
        reverse(dummy);
        return dummy;
    }
};