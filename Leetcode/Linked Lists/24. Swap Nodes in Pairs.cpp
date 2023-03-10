// Problem Link - https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr or head->next==nullptr)
            return head;
        ListNode* one = head, *two=head->next;
        if(head->next->next== nullptr)
        {
            ll temp=one->val;
            one->val=two->val;
            two->val = temp;
            return head;
        }
while(one and one->next!=nullptr)
{
    ll temp = one->val;
    one->val = two->val;
    two->val = temp;
    one = one->next->next;
    if(two->next!=nullptr)
    two = two->next->next;
}
        return head;
    }
};
