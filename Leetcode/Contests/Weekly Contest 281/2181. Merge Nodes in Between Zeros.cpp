// Problem Link - https://leetcode.com/contest/weekly-contest-281/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode* start = nullptr;
        ll sum = 0;
        ListNode* temp = head;
        while(temp)
        {
            if(temp->val==0)
            {
                ListNode* node = new ListNode(sum);
                if(start==nullptr)
                    start = node;
                if(ans==nullptr)
                    ans = node;
                else
                {
                    ans->next = node;
                    ans = node;
                }
                sum = 0;
            }
            sum+=temp->val;
            temp = temp->next;
        }
        return start->next;
    }
};