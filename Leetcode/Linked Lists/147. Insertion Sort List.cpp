// Problem Link - https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
       ListNode* dummy = new ListNode(100000);
       while(head)
       {
           ListNode* sortedList = dummy;
           ListNode* unsortListNext = head->next;
           
           while(sortedList->next and sortedList->next->val<head->val)
           {
               sortedList = sortedList->next;
           }
           
           head->next = sortedList->next;
           sortedList->next = head;
           head = unsortListNext;
       }
        return dummy->next;
    }
};
