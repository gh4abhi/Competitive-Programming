// Problem Link - https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr or k==0 or head->next==nullptr)
            return head;
        ll size = 0;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            size++;
            temp = temp->next;
        }
        k = k%size;
        if(k==0)
            return head;
        temp = head;
        for(ll i=0;i<size-k-1;i++)
        {
            temp = temp->next;
        }
        ListNode* rotatedPart = temp->next;
        temp->next = nullptr;
        ListNode* end = rotatedPart; 
        while(end->next!=nullptr)
        {
            end = end->next;
        }
        end->next = head;
        head = rotatedPart;
        return head;
    }
}; 
