// Problem Link - https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(head==nullptr or head->next==nullptr)
           return head;
       ListNode* cur = head, *pre = nullptr, *fow = nullptr,*le = nullptr,*start = nullptr;
ll count= 1;
        while(count<right+1)
        {
            fow = cur->next;
            if(count==left)
            {
                le = pre;
                start = cur;
            }
            else if(count>left and count<right)
            {
                cur->next = pre;
            }
            else if(count==right)
            {
                cur->next = pre;
                if(le==nullptr)
                    head = cur;
                else
                    le->next = cur;
                start->next = fow;
            }
            pre = cur;
            cur = fow;
            count++;
        }
        return head;
    }
};
