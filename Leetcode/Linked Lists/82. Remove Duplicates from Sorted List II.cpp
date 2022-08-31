// Problem Link - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* node = head;
        ListNode* pre = dummy;
        while(node)
        {
            if(node->next)
            {
                if(node->val==node->next->val)
                {
                    while(node and node->next and node->val==node->next->val)
                        node = node->next;
                    if(node==nullptr)
                        pre->next = nullptr;
                    else
                        pre->next = node->next, node = node->next;
                }
                else
                    pre = node,node = node->next;
            }
            else
                pre = node,node = node->next;
        }
        return dummy->next;
    }
};