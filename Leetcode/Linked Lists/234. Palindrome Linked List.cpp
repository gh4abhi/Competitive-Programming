// Problem Link - https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr or head->next==nullptr)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next and fast->next->next)
            fast = fast->next->next, slow = slow->next;
        ListNode* temp = slow->next;
        ListNode* pre = nullptr;
        while(temp)
        {
            ListNode* nex = temp->next;
            temp->next = pre;
            pre = temp;
            temp = nex;
        }
        slow->next = pre;
        ListNode* op = head;
        slow = slow->next;
        ListNode* first = head;
        while(slow)
        {
            if(slow->val!=first->val)
                return false;
            slow = slow->next;
            first = first->next;
        }
        return true;
    }
};