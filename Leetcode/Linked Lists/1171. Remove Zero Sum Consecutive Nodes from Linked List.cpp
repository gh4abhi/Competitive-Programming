// Problem Link - https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ll ok = -1;
        dummy->next = head;
        ListNode* temp = head;
        unordered_map<ll,ll> op;
        unordered_map<ll,ListNode*> m;
        unordered_map<ll,ListNode*> mn;
        op[0] = ok;
        m[ok] = dummy;
        mn[0] = dummy;
        ll sum = 0;
        ok+=1;
        while(temp)
        {
            sum += temp->val;
            if(op.count(sum) and m[op[sum]]==mn[sum] and op[sum]<ok)
                m[op[sum]]->next = temp->next, ok = op[sum];
            else
                op[sum] = ok, m[ok] = temp, mn[sum] = temp;
            ok+=1;
            temp = temp->next;
        }      
        return dummy->next;
    }
};