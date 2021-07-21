// Problem Link - https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* ans = nullptr, *ansTemp=nullptr;
        int carry = 0;
        while(n1!=nullptr or n2!=nullptr)
        {
            int sum = 0;
            
            if(n1==nullptr)
            {
            sum = n2->val + carry;
            carry = sum/10;
                sum = sum%10;
                n2 = n2->next;
            }
            else if(n2==nullptr)
            {
            sum = n1->val + carry;
            carry = sum/10;
                sum = sum%10;
                n1 = n1->next;
            }
            else
            {
            sum = n1->val + n2->val + carry;
            carry = sum/10;
                sum = sum%10;
                n1=n1->next;
                n2=n2->next;
            }
            
            ListNode* newNode = new ListNode(sum);
            if(ans==nullptr and newNode!=nullptr)
            {
                ans = newNode;
                ansTemp = newNode;
            }
            else
            {
                if(newNode!=nullptr)
                {
                ansTemp->next = newNode;
                    ansTemp = newNode;
            }
            }
        }
        if(carry>0)
        {
            ListNode* newNode = new ListNode(carry);
                ansTemp->next = newNode;
                    ansTemp = newNode;
        }
        return ans;
    }
};
