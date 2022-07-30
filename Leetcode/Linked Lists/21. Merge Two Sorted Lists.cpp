// Problem Link - https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        if(l1->val>l2->val)
            swap(l1,l2);
        ListNode* head = l1;
        while(l1 and l2)
        {
            ListNode* temp  = l1;
            while(l1 and l1->val<=l2->val)
                temp = l1, l1 = l1->next;
            temp->next = l2;
            swap(l1,l2);
        }
        return head;
    }
};