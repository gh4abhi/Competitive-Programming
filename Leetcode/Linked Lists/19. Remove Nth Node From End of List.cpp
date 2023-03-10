// Problem Link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* firstPointer = head;
        ListNode* secondPointer = head;
        
        while(n--)
        {
             if(secondPointer==nullptr)
            {
                return secondPointer;
            }
            secondPointer = secondPointer->next;
        }
        
        if(secondPointer==nullptr)
        {
            return firstPointer->next;
        }
        
        while(secondPointer!=nullptr)
        {
            secondPointer = secondPointer->next;
            if(secondPointer==nullptr)
            {
                firstPointer->next = firstPointer->next->next;
            }
            else
            {
                firstPointer = firstPointer->next;
            }
        }
        
        return head;
    }
};
