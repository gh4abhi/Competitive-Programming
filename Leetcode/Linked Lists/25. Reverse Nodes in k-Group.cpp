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
    
    ListNode *th = nullptr, *tt = nullptr, *oh = nullptr, *ot = nullptr;
    
    void addFirstNode(ListNode* node)
    {
        if(th==nullptr)
        {
            th = node;
            tt = node;
        }
        else
        {
            node->next = th;
            th = node;
        }
    }
    
    ll findLength(ListNode* head)
    {
        ll n = 0;
        ListNode*temp = head;
        while(temp!=nullptr)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr or head->next==nullptr or k==1)
            return head;
        ListNode* cur = head, *fow = nullptr;
        ll n = findLength(head);
        
        while(n>=k)
        {
            ll ck = k;
            while(ck--)
            {
                fow = cur->next;
                cur->next = nullptr;
                addFirstNode(cur);
                cur = fow;
            }
            if(oh==nullptr)
            {
                oh = th;
                ot = tt;
            }
            else
            {
                ot->next = th;
                ot = tt;
            }
            th = nullptr;
            tt = nullptr;
            n-=k;
        }
        ot->next = cur;
        return oh;
    }
};
