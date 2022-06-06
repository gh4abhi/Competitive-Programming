// Problem Link - https://leetcode.com/problems/intersection-of-two-linked-lists/

#define ll int

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,ll> m;
        ListNode* temp = headA;
        while(temp)
            m[temp]++,temp = temp->next;
        temp = headB;
        while(temp)
        {
            if(m.count(temp))
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};