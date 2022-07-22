// Problem Link - https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr)
            return head;
        ListNode* small = new ListNode(-1e9);
        ListNode* large = new ListNode(-1e9);
        ListNode* ans1 = small;
        ListNode* ans2 = large;
        ListNode* temp = head;
        while(temp->next)
        {
            ListNode* op = temp->next;
            if(temp->val<x)
                small->next = temp, small = small->next,temp->next=nullptr;
            else
                large->next = temp, large = large->next,temp->next=nullptr;
            temp = op;
        }
        if(temp->val<x)
            small->next = temp, small = small->next,temp->next=nullptr;
        else
            large->next = temp, large = large->next,temp->next=nullptr;                
        ans1 = ans1->next;
        if(ans2->next)
        {
            ans2 = ans2->next;
            if(ans1==nullptr)
                return ans2;
            small->next = ans2;
        }
        return ans1;
    }
};