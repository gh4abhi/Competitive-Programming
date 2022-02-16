// Problem Link - https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr or head->next == nullptr)
             return head;
        ListNode* pre = nullptr, *fow = nullptr, *cur = head;
        while(cur!=nullptr)
        {
            fow = cur->next;
            cur->next=pre;
            pre = cur;
            cur = fow;
        }
        return pre;
    }
};
