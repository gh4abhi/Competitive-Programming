// Problem Link - https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* pre = dummy;
        ListNode* nex = dummy;
        ll count = 0;
        while(cur->next)
            count++,cur=cur->next;
        while(count>=k)
        {
            cur = pre->next;
            nex = cur->next;
            ll op = k-1;
            while(op--)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count-=k;
        }
        return dummy->next;
    }
};
